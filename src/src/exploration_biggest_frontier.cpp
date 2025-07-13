// session 4: Navigation, mapping and exploration
// Mohammad Alikhani 
// 16 April 2025

#include "exploration_base.h"

class ExplorationBiggestFrontier : public ExplorationBase
{
protected:
    //////////////////////////////////////////////////////////////////////
    // TODO 1a: if you need your own attributes (variables) and/or
    //          methods (functions), define them HERE
    //////////////////////////////////////////////////////////////////////
    
    
    double time_max_goal_;        // max time to reach a goal before aborting
    double min_frontier_size_;    // ignore frontiers smaller than this
    
    // function to find the largest frontier:
    int getBiggestFrontierIndex()
    {
      int index_biggest = -1;
      double max_size = -1.0;
      for (size_t i = 0; i < frontiers_msg_.frontiers.size(); i++)
      {
        double s = frontiers_msg_.frontiers[i].size;
        if (s > max_size)
        {
          max_size = s;
          index_biggest = i;
        }
      }
      return index_biggest;
    }

    //////////////////////////////////////////////////////////////////////
    // TODO 1a END
    //////////////////////////////////////////////////////////////////////

public:
    ExplorationBiggestFrontier();

protected:
    bool replan() override;
    geometry_msgs::msg::Pose decideGoal() override;
};

ExplorationBiggestFrontier::ExplorationBiggestFrontier()
  : ExplorationBase("exploration_biggest_frontier")
{
    //////////////////////////////////////////////////////////////////////
    // TODO 1b: You can set the value of attributes using ros param
    //          for changing the value without need of recompiling.
    //////////////////////////////////////////////////////////////////////
    
    // loading params:
    get_parameter_or("time_max_goal",    time_max_goal_,    5.0);
    get_parameter_or("min_frontier_size", min_frontier_size_, 5.0);

    //////////////////////////////////////////////////////////////////////
    // TODO 1b END
    //////////////////////////////////////////////////////////////////////
}


geometry_msgs::msg::Pose ExplorationBiggestFrontier::decideGoal()
{
    geometry_msgs::msg::Pose g;

    ////////////////////////////////////////////////////////////////////
    // TODO 2: decide goal (pick the largest frontier)
    ////////////////////////////////////////////////////////////////////

    // 1) Finding the biggest frontier index
    int i_biggest = getBiggestFrontierIndex();
    if (i_biggest < 0)
    {
      // No frontier found => fallback 
      RCLCPP_WARN(get_logger(), "No frontiers available, returning current pose as fallback");
      return robot_pose_;
    }

    // 2) Retrieving the chosen frontier
    auto &f = frontiers_msg_.frontiers[i_biggest];

    // ignore if frontier is too small
    if (f.size < min_frontier_size_)
    {
      RCLCPP_WARN(get_logger(), "Biggest frontier < min_frontier_size, ignoring => fallback");
      return robot_pose_;
    }

    // 3) Filling the Pose with the frontier's center (center_free_point)
    g.position = f.center_point;
    g.orientation = robot_pose_.orientation; // or zero yaw if you prefer

    // 4) Checking if valid
    double path_length;
    bool valid = isValidGoal(g, path_length);
    if (!valid)
    {
      RCLCPP_WARN(get_logger(), "Biggest frontier is not a valid goal => fallback");
      return robot_pose_;
    }

    ////////////////////////////////////////////////////////////////////
    // TODO 2 END
    ////////////////////////////////////////////////////////////////////

    return g;
}


bool ExplorationBiggestFrontier::replan()
{
    ////////////////////////////////////////////////////////////////////
    // TODO 3: replan
    ////////////////////////////////////////////////////////////////////

    // 1) If the robot has been trying for too long, replan
    if (goal_time_ > time_max_goal_)
    {
      RCLCPP_INFO(get_logger(), "Time to reach goal exceeded time_max_goal_. Replanning...");
      return true;  // triggers a new 'decideGoal()'
    }

    // 2) checking if the robot is 'stuck' (goal_distance_ not decreasing)
    static double old_distance = 9999.0;
    if (fabs(old_distance - goal_distance_) < 0.01)
    {
      RCLCPP_INFO(get_logger(), "Robot not making progress. Replanning...");
      return true;
    }
    old_distance = goal_distance_;

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
  auto node = std::make_shared<ExplorationBiggestFrontier>();
  exec.add_node(node);
  exec.spin();

  return 0;
}
