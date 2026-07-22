# Subsets II

## Problem

Given an integer array `nums` that may contain duplicates, return all possible **unique subsets**.

---

# Brute Force

## Idea

Generate all subsets and remove duplicates using a `set`.

### Complexity

- **Time:** Exponential + Set overhead
- **Space:** Exponential

---

# Optimal Approach (Backtracking)

## Key Observations

- Sort the array to group duplicate values.
- Every recursive call already represents one valid subset.
- Skip duplicate choices at the same recursion level.

### Explanation

- Sort the array.
- Store the current subset at the beginning of every recursive call.
- Iterate through all remaining elements using a `for` loop.
- Skip duplicate values at the same recursion level.
- Choose the current element, recurse, then backtrack.

---

## Algorithm

1. Sort the array.
2. Store the current subset.
3. Iterate from `start` to `n-1`.
4. Skip duplicates.
5. Choose the current element.
6. Recurse with `j + 1`.
7. Backtrack.

---

## Complexity

- **Time:** `O(2^N)`
- **Space:** `O(N)`

---

# Code

```cpp
class Solution {
public:
    void solve(vector<int>& nums,vector<int>& curr, vector<vector<int>>&ans, int i){
        ans.push_back(curr);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]){
                continue;
            }
            curr.push_back(nums[j]);
            solve(nums,curr,ans,j+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(nums.begin(),nums.end());
        solve(nums,curr,ans,0);
        return ans;
    }
};
```

---

# Interview Discussion

- Why sort?
  - To group duplicate values together.
- Why `j > start`?
  - To skip duplicates only at the current recursion level.
- Why use a `for` loop?
  - Every recursive call chooses one element from all remaining candidates.

---

# What I Learned ⭐

- Duplicate subsets are avoided by skipping duplicate choices, not duplicate answers.
- Every recursive call itself is a valid subset.
- This follows the **for-loop backtracking** pattern.