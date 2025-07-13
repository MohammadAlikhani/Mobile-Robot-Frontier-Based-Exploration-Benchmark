// session 4: Navigation, mapping and exploration
// Mohammad Alikhani 
// 16 April 2025

#include "exploration_base.h"

class ExplorationClosestFrontier : public ExplorationBase
{
  protected:
    //////////////////////////////////////////////////////////////////////
    // TODO 1a: if you need your own attributes (variables) and/or
    //          methods (functions), define them HERE
    //////////////////////////////////////////////////////////////////////

    
    double time_max_goal_;        // max time to reach a goal before aborting
    double min_frontier_size_;    // ignore frontiers smaller than this

    // finding the index of the frontier closest to the current robot pose
    int getClosestFrontierIndex()
    {
      if (frontiers_msg_.frontiers.empty()) return -1;
      
      // Robot’s current position
      double rx = robot_pose_.position.x;
      double ry = robot_pose_.position.y;
      
      int index_closest = -1;
      double min_dist = 1e9;  // large initial value

      // Iterate over all frontiers
      for (size_t i = 0; i < frontiers_msg_.frontiers.size(); i++)
      {
        double fx = frontiers_msg_.frontiers[i].center_point.x;
        double fy = frontiers_msg_.frontiers[i].center_point.y;
        double dist = std::hypot(rx - fx, ry - fy);  // Euclidean distance

        if (dist < min_dist) {
          min_dist = dist;
          index_closest = i;
        }
      }
      return index_closest;
    }

    //////////////////////////////////////////////////////////////////////
    // TODO 1a END
    //////////////////////////////////////////////////////////////////////

  public:
    ExplorationClosestFrontier();

  protected:
    bool replan() override;
    geometry_msgs::msg::Pose decideGoal() override;
};


ExplorationClosestFrontier::ExplorationClosestFrontier()
  : ExplorationBase("exploration_closest_frontier")
{
    //////////////////////////////////////////////////////////////////////
    // TODO 1b: You can set the value of attributes using ros param
    //          for changing the value without need of recompiling.
    //////////////////////////////////////////////////////////////////////
    
    get_parameter_or("time_max_goal",     time_max_goal_,    20.0);
    get_parameter_or("min_frontier_size", min_frontier_size_, 5.0);

    //////////////////////////////////////////////////////////////////////
    // TODO 1b END
    //////////////////////////////////////////////////////////////////////
}


geometry_msgs::msg::Pose ExplorationClosestFrontier::decideGoal()
{
    geometry_msgs::msg::Pose g;

    ////////////////////////////////////////////////////////////////////
    // TODO 2: decide goal
    ////////////////////////////////////////////////////////////////////

    // 1) Get the index of the closest frontier
    int i_closest = getClosestFrontierIndex();
    if (i_closest < 0) 
    {
      // No frontier found => fallback to robot_pose_ or do something safe
      RCLCPP_WARN(get_logger(), "No frontiers found, returning current robot pose");
      return robot_pose_;
    }

    // 2) Checking the frontier's size
    auto &frontier = frontiers_msg_.frontiers[i_closest];
    if (frontier.size < min_frontier_size_)
    {
      // Frontier might be too small to bother traveling to
      RCLCPP_WARN(get_logger(), "Closest frontier is below min_frontier_size, ignoring");
      return robot_pose_;
    }

    // 3) Building the Pose from the frontier's center
    g.position = frontier.center_point;
    g.orientation = robot_pose_.orientation;  

    // 4)Validating the goal
    double path_length;
    bool valid = isValidGoal(g, path_length);
    if (!valid)
    {
      RCLCPP_WARN(get_logger(), "Closest frontier is not a valid goal => fallback");
      return robot_pose_;
    }

    ////////////////////////////////////////////////////////////////////
    // TODO 2 END
    ////////////////////////////////////////////////////////////////////

    return g;
}

bool ExplorationClosestFrontier::replan()
{
    ////////////////////////////////////////////////////////////////////
    // TODO 3: replan
    ////////////////////////////////////////////////////////////////////

    // checking if we've spent too long on the current goal
    if (goal_time_ > time_max_goal_)
    {
      RCLCPP_INFO(get_logger(), "Goal taking too long, replanning...");
      return true;
    }

    // Checking if we're 'stuck' and no decrease in goal_distance_
    static double old_dist = 1e9;
    if (fabs(old_dist - goal_distance_) < 0.01)
    {
      RCLCPP_INFO(get_logger(), "No progress to goal, replanning...");
      return true;
    }
    old_dist = goal_distance_;

    ////////////////////////////////////////////////////////////////////
    // TODO 3 END
    ////////////////////////////////////////////////////////////////////

    // Replan ANYWAY if the robot reached or aborted the goal (DO NOT ERASE THE FOLLOWING LINES)
    if (robot_status_ != 0) return true;

    return false;
}


////// MAIN ////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::executors::MultiThreadedExecutor exec;
  auto node = std::make_shared<ExplorationClosestFrontier>();
  exec.add_node(node);
  exec.spin();

  return 0;
}
