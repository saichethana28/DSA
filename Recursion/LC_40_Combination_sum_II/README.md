# Combination Sum II

## Problem

Given an array `candidates` (may contain duplicates) and an integer `target`, return all **unique combinations** where the chosen numbers sum to `target`.

- Each element can be used **only once**.
- The solution set must not contain duplicate combinations.

---

# Brute Force

## Idea

Generate all possible combinations using recursion and store the valid ones in a `set` to remove duplicates.

### Complexity

- **Time:** Exponential + Set insertion overhead
- **Space:** Exponential

---

# Optimal Approach (Backtracking)

## Key Observations

- Each element can be used **only once**, so recurse with `j + 1`.
- Sort the array to group duplicate values together.
- Skip duplicate choices at the **same recursion level**.
- Since the array is sorted, stop exploring when the current candidate exceeds the remaining target.

### Explanation

- Sort the array so that duplicate values become adjacent and combinations are generated in sorted order.
- Start recursion from index `0`. At each recursive call, iterate through all remaining candidates using a `for` loop and try each one as the next element of the combination.
- Skip duplicate values at the **same recursion level** to avoid generating identical combinations.
- If the current candidate is greater than the remaining target, stop exploring the current branch since all subsequent elements will also be larger.
- Add the current element to the current combination and recurse with:
  - Remaining target: `target - candidates[j]`
  - Next starting index: `j + 1`
- After returning from recursion, remove the last element to backtrack and explore other possibilities.
- Whenever the remaining target becomes `0`, store the current combination in the answer.

---

## Algorithm

1. Sort the array.
2. Start recursion from index `0`.
3. Iterate through all remaining candidates using a `for` loop.
4. Skip duplicate values at the same recursion level.
5. If the current candidate exceeds the remaining target, stop exploring the current branch.
6. Choose the current element and recurse with:
   - `target - candidates[j]`
   - `start = j + 1`
7. Backtrack by removing the last chosen element.
8. If `target == 0`, add the current combination to the answer.

---

## Complexity

- **Time:** `O(2^N)` (Worst case)
- **Space:** `O(N)` (Recursion stack + current combination)

---

# Code

```cpp
class Solution {
public:
    void solve(vector<int>& candidates, vector<int>& curr,
               vector<vector<int>>& ans,
               int target, int start) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int j = start; j < candidates.size(); j++) {

            if (j > start && candidates[j] == candidates[j - 1])
                continue;

            if (candidates[j] > target)
                break;

            curr.push_back(candidates[j]);

            solve(candidates, curr, ans,
                  target - candidates[j], j + 1);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, curr, ans, target, 0);

        return ans;
    }
};
```

---

# Interview Discussion

- Why do we sort the array?
  - To group duplicate values together and enable pruning.

- Why use `j + 1` instead of `j`?
  - Because each element can be used only once.

- Why use a `for` loop instead of Take / Don't Take recursion?
  - Each recursive call must choose **one element from all the remaining candidates**, so we iterate through every available choice.

- Why do we skip duplicates only when `j > start`?
  - It skips duplicate choices within the **same recursive call**, while still allowing duplicate values to be used in deeper recursion levels.

- Why is `break` used instead of `continue`?
  - Since the array is sorted, if the current candidate exceeds the remaining target, every following candidate will also exceed it.

---

# What I Learned ⭐

- Not every backtracking problem follows the **Take / Don't Take** recursion pattern.
- A **for loop** is used when each recursive call has multiple choices.
- Sorting helps both **avoid duplicate combinations** and **prune unnecessary recursion**.
- `j > start` skips duplicate branches only at the **same recursion level**.
- Backtracking follows the pattern: **Choose → Recurse → Backtrack**.