# 🤖 Frontier-Based Exploration with Weighted Goal Selection & Dynamic Replanning

> Mobile Robotics & Navigation · Universitat Politècnica de Catalunya (UPC)  
> **Author:** Mohammad Alikhani Najafabadi — mohammad.najafabadi@estudiantat.upc.edu  
> **Date:** 28 May 2025

This project benchmarks a **hybrid frontier-scoring rule** and a **distance-triggered replanner** to cut total travel during autonomous map exploration.  
Across **48 Gazebo / ROS 2 simulations** (small + large maps), the combo **α = 0 .2** (frontier-size bias) and **β = 0 .6** (replan when 60 % of the path remains) reduces travel by ≈ 10 % versus the classic “closest frontier + static replans” baseline.

---

## 📑 Table of Contents
1. [Concept](#concept)  
2. [Research Questions & Hypotheses](#rq)  
3. [Variables](#vars)  
4. [Simulation Design](#sim)  
5. [Results](#results)  
6. [Conclusions](#conclusions)  
7. [Reproduction Guide](#repro)  
8. [Reference](#reference)

---

<a name="concept"></a>
## 🌐 Concept

Frontier exploration chooses the next **frontier cell cluster** to visit.  
Two extremes:

| Strategy | Pros | Cons |
|----------|------|------|
| **Closest** | Low step-cost, energy-efficient | May harvest little new space |
| **Largest** | Maximises info gain | Wasteful detours on small maps |

We propose a **weighted score** plus a **dynamic replan trigger**:

```math
\text{score}(f)
  = \alpha \frac{\text{size}(f)}{\max\text{size}}
  - (1-\alpha)\frac{\text{dist}(f)}{\max\text{dist}}
