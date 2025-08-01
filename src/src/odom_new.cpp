// Deliverable 1 - odom_new
// Mohammad Alikhani Najafabadi
// 27 February 2025

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "tf2/utils.h"                             // getYaw
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp" // toMsg

class OdomNew : public rclcpp::Node
{
  // ----- Attributes -----
  rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_state_sub_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr original_odom_sub_;
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_new_pub_;

  bool odom_initialized_, received_joint_state_;
  rclcpp::Time last_time_;

  double x_, y_, th_;
  double radius_, wheel_distance_;

public:
  // ----- Methods -----
  // Constructor
  OdomNew()
      : Node("odom_new")
  {
    // initialization
    received_joint_state_ = false;
    odom_initialized_ = false;

    radius_ = 0.04;
    wheel_distance_ = 0.233;
    last_time_ = this->now();

    // subscribers
    joint_state_sub_ = this->create_subscription<sensor_msgs::msg::JointState>(
        "joint_states", 10, std::bind(&OdomNew::jointStatesCallback, this, std::placeholders::_1));
    original_odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "odom", 10, std::bind(&OdomNew::originalOdomCallback, this, std::placeholders::_1));

    // publisher
    odom_new_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("odom_new", 10);
  }

private:
  // Callback of joint state message
  void jointStatesCallback(const sensor_msgs::msg::JointState &msg)
  {
    // RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
    received_joint_state_ = true;

    // skip if no velocities
    if (msg.velocity.size() != 2)
      return;

    // skip if not initialized
    if (not odom_initialized_)
      return;

    // COMPUTATION OF NEW ODOMETRY
    double left_angular_vel = msg.velocity[0];
    double right_angular_vel = msg.velocity[1];

    rclcpp::Time time = msg.header.stamp;
    // RCLCPP_INFO(this->get_logger(), "Received left_angular_vel: %f (rad/s)\t right_angular_vel: %f (rad/s)", left_angular_vel, right_angular_vel);
    double dt = (time - last_time_).seconds();
    // RCLCPP_INFO(this->get_logger(), "dt: %fs", dt);
    double v_front = 0.0;
    double w = 0.0;

    //////// TODO //////
    double k00, k01, k02;
    double k10, k11, k12;
    double k20, k21, k22;
    double k30, k31, k32;
    double x__, y__, th__;
    
    v_front = (left_angular_vel + right_angular_vel)*radius_;
    w  = (left_angular_vel - right_angular_vel)*radius_/(2*wheel_distance_);
    k00 = v_front*cos(th_);
    k01 = v_front*sin(th_);
    k02 = w;
    
    k10 = v_front*cos(th_ + dt/2*k02);
    k11 = v_front*sin(th_ + dt/2*k02);
    k12 = w;

    k20 = v_front*cos(th_ + dt/2*k12);
    k21 = v_front*sin(th_ + dt/2*k12);
    k22 = w;

    k30 = v_front*cos(th_ + dt*k22);
    k31 = v_front*sin(th_ + dt*k22);
    k32 = w;

    x__ = x_ + dt/6*(k00 +2*(k10+k20)+k30);
    y__ = y_ + dt/6*(k01 +2*(k11+k21)+k31);
    th__ = th_ + dt/6*(k02 +2*(k12+k22)+k32);
    x_ += v_front *cos(th_)*dt;
    y_ += v_front *sin(th_)*dt;
    th_ += w*dt;
    
    //////// TODO //////

    // Fill odometry msg
    nav_msgs::msg::Odometry odom_msg;
    odom_msg.header.stamp = time;
    odom_msg.header.frame_id = "odom";
    odom_msg.child_frame_id = "base_footprint";
    odom_msg.pose.pose.position.x = x_;
    odom_msg.pose.pose.position.y = y_;
    tf2::Quaternion q;
    q.setRPY(0, 0, th_);
    odom_msg.pose.pose.orientation = tf2::toMsg(q);
    odom_msg.twist.twist.linear.x = v_front;
    odom_msg.twist.twist.angular.z = w;

    // PUBLISH MSG
    odom_new_pub_->publish(odom_msg);
    last_time_ = time;
  }

  // Callback of original odometry (just for initialization)
  void originalOdomCallback(const nav_msgs::msg::Odometry &msg)
  {
    // RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());

    if (received_joint_state_ and not odom_initialized_)
    {
      RCLCPP_INFO(this->get_logger(), "Received input odom, initializing new odom");
      x_ = msg.pose.pose.position.x;
      y_ = msg.pose.pose.position.y;
      th_ = tf2::getYaw(msg.pose.pose.orientation);
      last_time_ = msg.header.stamp;

      RCLCPP_INFO(this->get_logger(), "New odom initialized from input odom x_,y_,th_=%f,%f,%f", x_, y_, th_);
      odom_initialized_ = true;
    }
  }
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<OdomNew>());
  rclcpp::shutdown();
  return 0;
}
