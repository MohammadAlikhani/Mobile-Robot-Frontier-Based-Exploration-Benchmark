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
- **Exploration Strategy Variants**: pure "closest" (\( \alpha = 0 \)), pure "largest" (\( \alpha = 1 \)), or hybrid weighted.
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

