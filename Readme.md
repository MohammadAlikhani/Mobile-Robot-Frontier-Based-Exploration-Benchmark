# 🤖 Frontier-Based Exploration with Weighted Goal Selection & Dynamic Replanning

> Mobile Robotics & Navigation · Universitat Politècnica de Catalunya (UPC)  
> **Author:** Mohammad Alikhani Najafabadi
> **Date:** 28 May 2025

This project benchmarks a **hybrid frontier-scoring rule** and a **distance-triggered replanner** to cut total travel during autonomous map exploration.  
Across **48 Gazebo / ROS 2 simulations** (small + large maps), the combo **α = 0 .2** (frontier-size bias) and **β = 0 .6** (replan when 60 % of the path remains) reduces travel by ≈ 10 % versus the classic “closest frontier + static replans” baseline.

---

## 📑 Table of Contents
1. [Concept](#concept)  
2. [Research Questions & Hypotheses](#rq)  
3. [Variables](#vars)  
4. [Simulation and Results](#sim)    
8. [About the Package](#pkg)

---

<a name="concept"></a>
## 🌐 Concept

Frontier exploration chooses the next **frontier cell cluster** to visit.  
Two extremes:

| Strategy | Pros | Cons |
|----------|------|------|
| **Closest** | Low step-cost, energy-efficient | May harvest little new space |
| **Largest** | Maximises info gain | Wasteful detours on small maps |



<a name="rq"></a>
## 🔬 Research Questions& Hypotheses
| ID | Question | Hypothesis |
|----|----------|------------|
| **RQ1** | Does a weighted combination of frontier *size* vs. *distance* (parameter α) lower distance vs. pure strategies? | **H1** — ∃ α ∈ (0, 1) that beats α = 0 (closest) & α = 1 (largest). |
| **RQ2** | Does triggering a re-plan when only a fraction β of the path remains reduce detours? | **H2** — Replanning when 0<d<β×path lowers distance vs. static replan. |
| **RQ3** | Is there an interaction between α and β? | The optimal α depends on β (and vice-versa). |

We propose a **weighted score** plus a **dynamic replan trigger**:

## Hypotheses

### H₁ (Weighted score)

We define a scoring function that balances **frontier size** and **distance**:

```math
\text{score}(f)
  = \alpha \,\frac{\text{size}(f)}{\max \text{size}}
  - (1-\alpha)\,\frac{\text{dist}(f)}{\max \text{dist}}  
```

There exists an $$( \alpha \in (0, 1) \)$$ that yields **lower total travel** than:

$$\( \alpha = 0 \)$$ → pure closest (nearest-frontier)

$$\( \alpha = 1 \)$$ → pure largest (largest-frontier)

---

### H₂ (Adaptive replan)

If we abort and pick a new goal whenever:

```math
0 < \text{D}_\text{remaining} < \beta \times \text{(planned path length)}
```

Then we avoid long detours and further reduce total travel distance.

---
<a name="vars"></a>
## 🎛️ Variables

### 1. Independent Variables

- $$\( \alpha \)$$: the weight between "frontier size" and "frontier distance" in your goal-scoring function.
- $$\( \beta \)$$: the fraction of planned path length at which you trigger a replan.
- **Exploration Strategy Variants**: pure "closest" $$\( \alpha = 0 \)$$, pure "largest" $$\( \alpha = 1 \)$$, or hybrid weighted.
- **Replan Strategy Variants**: only abort on success/abort, versus distance-based, versus time-based, or combinations.

### 2. Dependent Variable(s)

- **Total distance traveled** (our primary metric).

---
<a name="sim"></a>
## 🏗️ Simulation and Results

- **Platform**: ROS 2 Humble · Nav2 · Gazebo  
- **Maps**: small (≈ 50 × 50 m) and large (≈ 120 × 120 m)  
- **Runs**: 4 α × 4 β × 3 repeats = **48** sims per map

| Map   | Best $$\alpha$$: | Best $$\beta$$ | Mean distance |
|--------|--------|--------|----------------|
| Small  | **0.2** | **0.6** | **33.199 m**   |
| Large  | **0.2** | **0.6** | **90.271 m**   |

---
<a name="pkg"></a>
## 🏗️ About the Package

This package was developed for Mobile Robotics and Navigation (MRN) of the Master in Automation and Robotics (MUAR) of the Universitat Politècnica de Catalunya (UPC).

This project is performed on Turtlebot4 lite platforms simulated and real.

### 1. Dependencies

For these practices you will need a PC with Ubuntu 22.04 and ros humble installed (ros-humble-desktop-full recommended).

Apart from ROS humble, the following dependencies are required for the practices. They all can be installed via apt:
- ssh
- git
- python3-colcon-common-extensions
- ignition-fortress
- ros-humble-rplidar-ros 
- ros-humble-rqt-tf-tree
- ros-humble-teleop-twist-keyboard
- ros-humble-turtlebot4-simulator 
- ros-humble-turtlebot4-desktop 
- ros-humble-turtlebot4-navigation 
- ros-humble-turtlebot4-node 
- ros-humble-turtlebot4-tutorials

#### 1.1. Setup script

For the students convenience, we provide an script to install the dependencies, configure a ros workspace (~/ros2_ws) and clone this package, in your personal laptop (Ubuntu 22.04 and ros humble required).
This script needs to be executed once. 

First, download the script:

```bash
wget --no-check-certificate -O mrn_setup.sh http://bit.ly/upc_mrn_laptop
```

Terminal output should say it downloaded the file successfully, otherwise, try again. 
Then, execute the script (your password will be required):

```bash
source mrn_setup.sh
```

Check that no errors occurred and then you can remove the script and the logs that were generated (rm mrn_setup.sh log_mrn_setup.log).

### 2. Example

#### 2.1. Compile `upc_mrn`

To check that everything is working you need first to compile the upc_mrn package:

```bash
cd ~/ros2_ws && colcon build --symlink-install --packages-up-to upc_mrn
```

#### 2.2. Simulation of turtlebot4 lite

And then, launch the simulation (gazebo ignition) of the Turtlebot4 lite (rgbd camera is not simulated for efficiency) in a room-like environment:

```bash
ros2 launch upc_mrn sim.launch.py world:=rooms gui:=false
```

**`sim.launch.py` arguments:**

- `gui`: Whether launch the gazebo GUI or not. (default: `true`)
- `world`: which world to load. Available: `empty`, `rooms`, `simple`, `large`, `small`. (default: `empty`)
- `x`, `y`, `yaw`: initial pose of the robot. (default: origin)
- `oak`: Whether a robot with the plugin of the OAK rbd camera or a robot without it. (default: `false`)

#### 2.3. SLAM_toolbox

In this example we will run the `slam_toolbox` to create a map of the environment.
In another terminal, run the launch:

```bash
ros2 launch upc_mrn slam.launch.yaml
```

Then, the visualization (RVIZ2) in a third terminal:

```bash
rviz2 -d ~/ros2_ws/src/upc_mrn/rviz/slam.rviz
```

And finally, to move the robot, run the `teleop_twist_keyboard` node in a fourth terminal:

```bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```

#### 2.4 Navigation

Instead of the teleoperation, we can launch the navigation (nav2) with a launch also provided:

```bash
ros2 launch upc_mrn nav.launch.yaml
```
