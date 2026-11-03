# Machine Learning — Notes

---

## What is Machine Learning?

A field of study that gives computers the ability to learn without being explicitly programmed.  
— Arthur Samuel, 1959

> More data + more learning time = better results  
> (Model finds more patterns and corrects more mistakes)

## Index

- [What is Machine Learning?](#what-is-machine-learning)
- [Types of Machine Learning](#types-of-machine-learning)
- [1. Supervised Learning](#1-supervised-learning)
- [2. Unsupervised Learning](#2-unsupervised-learning)
- [3. Reinforcement Learning](#3-reinforcement-learning)
- [Key Terminology](#key-terminology)
- [How ML Works — Big Picture](#how-ml-works--big-picture)
- [The Model Function](#the-model-function)
- [Type of Regression](#type-of-regression)
- [Cost Function](#cost-function)
- [Gradient Descent](#gradient-descent)

---

## Types of Machine Learning

| Type | Data Given | How it Learns |
|---|---|---|
| Supervised | Data WITH answers | Compares prediction to correct answer |
| Unsupervised | Data WITHOUT answers | Finds hidden patterns silently |
| Reinforcement | No data, just environment | Gets reward/penalty for actions |

---

## 1. Supervised Learning

### Regression → Output is a NUMBER

- Predict house price → ₹45,00,000
- Predict temperature → 34°C
- Predict salary → ₹8 LPA

**Algorithms:**

- **Linear Regression** → straight line relationship
  - Example: More experience = more salary
- **Polynomial Regression** → curved relationship
  - Example: House price vs age of house

---

### Classification → Output is a CATEGORY

**Binary Classification** → 2 options only

- Spam / Not Spam
- Cancer / No Cancer
- Pass / Fail

**Multi-class Classification** → more than 2 options

- Cat / Dog / Bird
- Digit recognition (0-9)
- Language detection (Hindi/English/Telugu...)

| Problem | Type | Output |
|---|---|---|
| Email spam | Binary | Spam / Not Spam |
| Fruit recognition | Multi-class | Apple/Banana/Mango |
| Sentiment analysis | Multi-class | Positive/Negative/Neutral |
| Dog breed | Multi-class | 100+ breeds |

---

## 2. Unsupervised Learning

**1. Clustering** → group similar things

- Algorithms: K-Means, DBSCAN, Hierarchical
- Example: Group customers by shopping behavior

**2. Dimensionality Reduction** → simplify data

- Algorithms: PCA, t-SNE, Autoencoders
- Example: 100 features → 10 most important features

**3. Anomaly Detection** → find the odd one out

- Algorithms: Isolation Forest, Autoencoders
- Example: Fraud detection, defective product detection

**4. Association Rule Learning** → find what appears together

- Algorithms: Apriori, FP-Growth
- Example: People who buy bread also buy butter

---

## 3. Reinforcement Learning

- Agent learns by **trial and error**
- Gets **reward** for good action, **penalty** for bad

**Algorithms:** Q-Learning, PPO

**Examples:**

- Game playing (Chess, AlphaGo)
- Self-driving cars
- Robot walking

---

## Key Terminology

| Term | Symbol | Meaning |
|---|---|---|
| Training Set | — | Dataset used to train the model |
| Input Variable | x | Input feature |
| Output Variable | y | Target variable |
| No. of Training Examples | m | Total rows in dataset |
| Single Training Example | (x, y) | One row of data |
| i-th Training Example | x⁽ⁱ⁾, y⁽ⁱ⁾ | Specific row i in the table |

> **Note:** Superscript (i) means i-th example — NOT a power

---

## How ML Works — Big Picture

```
Training Set → Learning Algorithm → f (model/hypothesis)
```

Then:

```
x → f → ŷ
```

| Symbol | Name | Meaning |
|---|---|---|
| x | Feature | Input given to model |
| f | Model | The function that predicts |
| ŷ | y-hat | Model's prediction/estimate of y |

---

## The Model Function

$$
f_{w,b}(x) = wx + b
$$

| Term | Other Names | Meaning |
|---|---|---|
| w | weight, coefficient, parameter | slope |
| b | bias, coefficient, parameter | intercept |

> **Shorthand:** f(x) = wx + b

---

## Type of Regression

> **Univariate Linear Regression**  
> = Linear regression with **one input variable (x)**  
> "Uni" = one feature only

---

## Cost Function

**Goal:** Measure how wrong the model's predictions are

**Error for one example:**

```
ŷ - y  (prediction - actual)
```

**Squared Error Cost Function:**

$$
J(w,b) = \frac{1}{2m} \sum_{i=1}^{m} (\hat{y}^{(i)} - y^{(i)})^2
$$

$$
J(w,b) = \frac{1}{2m} \sum_{i=1}^{m} (wx^{(i)} + b - y^{(i)})^2
$$

| Part | Why |
|---|---|
| ŷ - y | error for one example |
| (ŷ - y)² | square it → no negative errors cancelling out |
| Σ | sum all errors together |
| ÷ m | get average error (not total) |
| ÷ 2 | math convenience for gradient descent later |

> Dividing by **m or 2m** — both work ✅  
> Called: **Squared Error Cost Function**  
> Goal of training: make **J(w,b) as small as possible**

## Gradient Descent

**Goal:** Automatically find w and b that minimize J(w,b)

- Works for **any** cost function, not just linear regression
- Calculates the slope at each point → decides which direction to move and by how much

**Update rule:**

$$
w = w - \alpha \frac{\partial}{\partial w} J(w,b)
$$

$$
b = b - \alpha \frac{\partial}{\partial b} J(w,b)
$$
 
| Symbol | Name | Meaning |
| --- | --- | --- |
| α (alpha) | Learning rate | How big each step is |
| d/dw J | Slope / Gradient | Direction and steepness |
 
### Example — Minimizing y = x²
 
Slope = 2x, α = 0.1, start at x = 4
 
| Step | x | Slope (2x) | New x |
| --- | --- | --- | --- |
| 1 | 4.00 | 8.0 | 3.20 |
| 2 | 3.20 | 6.4 | 2.56 |
| 3 | 2.56 | 5.12 | 2.05 |
| … | … | … | → 0 ✅ |
 
Slope shrinks → steps get smaller → converges to minimum
 
### ⚠️ Important Rule — Simultaneous Update
 
Always update w and b **at the same time** using temp variables:
 
$$
temp_w = w - \alpha \frac{\partial}{\partial w} J(w,b)
$$

$$
temp_b = b - \alpha \frac{\partial}{\partial b} J(w,b)
$$
``` 
w = temp_w
b = temp_b
```
 
> ❌ Do NOT update w first and then use the new w to compute b — it changes the whole equation