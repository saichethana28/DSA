# Subset Sum

## Problem

Given an array, return the sum of every possible subset in increasing order.

---

# Brute Force

## Idea

Generate every subset and compute its sum.

### Complexity

- **Time:** O(2^N)
- **Space:** O(N)

---

# Optimal Approach (Backtracking)

## Key Observations

- The recursion is identical to **Subsets**.
- Instead of storing the subset, store its running sum.

### Explanation

- Maintain the current subset sum.
- For every element:
  - Add it to the current sum.
  - Skip it.
- When all elements are processed, store the current sum.
- Sort the final answer.

---

## Algorithm

1. Start with `sum = 0`.
2. Take the current element.
3. Don't take the current element.
4. Store the sum when recursion reaches the end.
5. Sort the answer.

---

## Complexity

- **Time:** `O(2^N)`
- **Space:** `O(N)`

---

# Interview Discussion

- Why pass `sum` by value?
  - Each recursive call gets its own copy, so no backtracking is needed.
- Why sort at the end?
  - Recursion order doesn't guarantee sorted sums.

---

# What I Learned ⭐

- The recursion is identical to **Subsets**.
- Only the information stored at the base case changes.