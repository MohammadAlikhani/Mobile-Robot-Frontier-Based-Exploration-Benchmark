// Exploration project 
// Mohammad Alikhani Najafabadi
// exploration_project.cpp

#include "exploration_base.h"
#include <cmath>
#include <limits>
#include <vector>

class ExplorationProject : public ExplorationBase
{
protected:
    //////////////////////////////////////////////////////////////////////
    // TODO 1a: your own attributes/methods
    //////////////////////////////////////////////////////////////////////
    double alpha_;             // weight for frontier size vs. distance
    double beta_;              // replan threshold fraction of planned path
    double time_max_goal_;     // time‐out for a single goal
    double planned_path_length_;  // cached length to current goal

    //////////////////////////////////////////////////////////////////////
    // TODO 1a END
    //////////////////////////////////////////////////////////////////////

public:
    ExplorationProject();

protected:
    bool replan() override;
    geometry_msgs::msg::Pose decideGoal() override;
};

ExplorationProject::ExplorationProject()
: ExplorationBase("exploration_project"),
  planned_path_length_(0.0)
{
    //////////////////////////////////////////////////////////////////////
    // TODO 1b: load params
    //////////////////////////////////////////////////////////////////////
    // declare & fetch α, β, time_max_goal
    declare_parameter("alpha",           0.5);
    declare_parameter("beta",            0.5);
    declare_parameter("time_max_goal",   10.0);

    get_parameter("alpha",        alpha_);
    get_parameter("beta",         beta_);
    get_parameter("time_max_goal", time_max_goal_);

    RCLCPP_INFO(get_logger(),
      "ExplorationProject: alpha=%.2f  beta=%.2f  time_max_goal=%.2f",
      alpha_, beta_, time_max_goal_);
    //////////////////////////////////////////////////////////////////////
    // TODO 1b END
    //////////////////////////////////////////////////////////////////////
}

geometry_msgs::msg::Pose ExplorationProject::decideGoal()
{
    geometry_msgs::msg::Pose best = robot_pose_;
    const auto &fronts = frontiers_msg_.frontiers;
    size_t N = fronts.size();
    if (N == 0) {
      RCLCPP_WARN(get_logger(), "No frontiers available");
      return best;
    }

    // 1) Gather sizes & path lengths
    std::vector<double> sizes(N), dists(N);
    double max_size = 0.0, max_dist = 0.0;
    for (size_t i = 0; i < N; ++i) {
      sizes[i] = fronts[i].size;
      max_size = std::max(max_size, sizes[i]);

      // build a temporary pose at the frontier center
      geometry_msgs::msg::Pose p;
      p.position    = fronts[i].center_point;
      p.orientation = robot_pose_.orientation;

      double L = computePathLength(p);
      if (L < 0) {
        dists[i] = -1.0;            // unreachable
      } else {
        dists[i] = L;
        max_dist = std::max(max_dist, L);
      }
    }

    // 2) Score and pick best frontier
    double best_score = -std::numeric_limits<double>::infinity();
    int best_i = -1;
    for (size_t i = 0; i < N; ++i) {
      if (dists[i] < 0) continue;           // skip unreachable
      double ns = (max_size > 0 ? sizes[i]/max_size : 0.0);
      double nd = (max_dist > 0 ? dists[i]/max_dist : 0.0);
      double score = alpha_*ns - (1.0 - alpha_)*nd;
      if (score > best_score) {
        best_score = score;
        best_i = (int)i;
      }
    }

    if (best_i < 0) {
      RCLCPP_WARN(get_logger(), "No reachable frontier found");
      return best;
    }

    // 3) Build and return the goal pose
    planned_path_length_ = dists[best_i];
    best.position    = fronts[best_i].center_point;
    best.orientation = robot_pose_.orientation;

    RCLCPP_INFO(get_logger(),
      "Picked frontier #%d: size=%.1f  dist=%.2f  score=%.2f",
      best_i, sizes[best_i], dists[best_i], best_score);

    return best;
}

bool ExplorationProject::replan()
{
    // 1) always replan if goal completed or aborted
    if (robot_status_ != 0) {
      return true;
    }
    // 2) dynamic distance‐based replan
    if (goal_distance_ >= 0 &&
        goal_distance_ < beta_ * planned_path_length_)
    {
      RCLCPP_INFO(get_logger(),
        "Replan: distance %.2f < β·planned %.2f",
        goal_distance_, beta_*planned_path_length_);
      return true;
    }
    // 3) time‐out fallback
    if (goal_time_ > time_max_goal_) {
      RCLCPP_INFO(get_logger(),
        "Replan: time %.2f > max_goal %.2f",
        goal_time_, time_max_goal_);
      return true;
    }
    return false;
}

////// MAIN ////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::executors::MultiThreadedExecutor exec;
  auto node = std::make_shared<ExplorationProject>();
  exec.add_node(node);
  exec.spin();
  return 0;
}
