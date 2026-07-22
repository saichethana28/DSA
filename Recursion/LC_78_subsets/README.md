# Subsets

## Problem

Given an integer array `nums` of unique elements, return all possible subsets (the power set).

---

# Brute Force

## Idea

Generate all possible subsets by deciding for every element whether to **take** it or **not take** it.

### Complexity

- **Time:** O(2^N)
- **Space:** O(N)

---

# Optimal Approach (Backtracking)

## Key Observations

- Every element has only **two choices**:
  - Take
  - Don't Take
- Every leaf node in the recursion tree represents one subset.

### Explanation

- Start recursion from index `0`.
- For every element:
  - Include it in the current subset.
  - Exclude it from the current subset.
- When all elements are processed (`i == n`), store the current subset.

---

## Algorithm

1. Start recursion from index `0`.
2. Include the current element.
3. Recurse for the next index.
4. Backtrack by removing the last element.
5. Exclude the current element.
6. Recurse for the next index.
7. Store the subset when all elements are processed.

---

## Complexity

- **Time:** `O(2^N)`
- **Space:** `O(N)`

---

# Code

```cpp
class Solution {
public:
    void solve(vector<int>& nums, vector<int>& curr,
               vector<vector<int>>& ans, int i){

        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(nums, curr, ans, i + 1);

        curr.pop_back();

        solve(nums, curr, ans, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> curr;

        solve(nums, curr, ans, 0);

        return ans;
    }
};
```

---

# Interview Discussion

- Why use Take / Don't Take?
  - Every element has exactly two choices.
- Why backtrack?
  - To restore the subset before exploring another choice.

---

# What I Learned ⭐

- Subsets follow the classic **Take / Don't Take** recursion.
- Every leaf node represents one valid subset.