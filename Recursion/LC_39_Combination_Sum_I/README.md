# Combination Sum - I

## Problem

Given an array of **distinct positive integers** `candidates` and a target integer `target`, return all unique combinations of candidates where the chosen numbers sum to `target`.

- A candidate can be chosen **unlimited times**.
- The combinations can be returned in any order.

---

# Brute Force Approach

## Idea

Generate all possible sequences by repeatedly choosing any element and check whether the sum equals the target.

Since every element can be selected multiple times, this explores a huge number of unnecessary possibilities and may generate duplicate combinations.

### Algorithm

1. Generate every possible sequence.
2. Calculate its sum.
3. If the sum equals the target, store the sequence.
4. Remove duplicate combinations.

### Complexity

- **Time:** Exponential (Very High)
- **Space:** Exponential

---

# Optimal Approach (Backtracking)

## Key Observation

At every index, we have only **two choices**:

1. **Take** the current element.
   - Stay at the same index because the current element can be used again.
2. **Don't Take** the current element.
   - Move to the next index since we have decided not to use this element anymore.

Whenever the remaining target becomes **0**, we have found one valid combination.

---

## Algorithm

1. If `target == 0`, store the current combination and return.
2. If `target < 0` or all elements are processed, return.
3. Include the current element and recurse with:
   - same index
   - reduced target
4. Backtrack by removing the last element.
5. Exclude the current element and recurse with the next index.

---

## Complexity

- **Time:** Exponential (depends on the number of possible combinations)
- **Space:** `O(Target / Minimum Candidate)` (Recursion stack + current combination)

---

# Code

```cpp
class Solution {
public:
    void solve(vector<int>& candidates, int target,
               vector<vector<int>>& ans,
               vector<int>& curr,
               int i) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (target < 0 || i == candidates.size()) {
            return;
        }

        // Take
        curr.push_back(candidates[i]);
        solve(candidates, target - candidates[i], ans, curr, i);

        // Backtrack
        curr.pop_back();

        // Don't Take
        solve(candidates, target, ans, curr, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, target, ans, curr, 0);

        return ans;
    }
};
```

---

# Interview Discussion

- Since all numbers are **positive**, once `target == 0`, no further element can be added without exceeding the target. Hence, store the current combination and return.
- Staying at the **same index** after taking an element allows unlimited reuse of that element.
- Moving to the **next index** after not taking an element prevents duplicate combinations.

---

# Recursion Tree

```
solve(i, target)
│
├── Take
│      ↓
│ solve(i, target - candidates[i])
│
└── Don't Take
       ↓
  solve(i + 1, target)
```

- **Take → Stay at the same index**
- **Don't Take → Move to the next index**

---

# Tips 💡

- Every recursive call answers:
  > **"Can I form the remaining target from this index?"**
- `target == 0` means a valid combination is found.
- Backtracking (`push_back()` → recurse → `pop_back()`) restores the previous state for exploring other choices.
- If all elements are **positive**, stop immediately when `target == 0` or `target < 0`.

---

# What I Learned ⭐

- Problems allowing **unlimited reuse** of an element usually keep the **same index** in the Take branch.
- The Don't Take branch always moves to the next index, ensuring each element is considered only once for exclusion.
- Think of recursion as exploring choices, while backtracking restores the state to explore the next possibility.
