# Combination Sum III

## Problem

Find all possible combinations of `k` numbers (1 to 9) whose sum equals `n`.

Each number can be used only once.

---

# Brute Force

## Idea

Generate every possible combination of numbers from 1 to 9 and check if it satisfies the constraints.

### Complexity

- **Time:** Exponential
- **Space:** O(K)

---

# Optimal Approach (Backtracking)

## Key Observations

- Numbers are fixed from `1` to `9`.
- Every number can be used only once.
- Move to the next number after choosing the current one.
- Stop exploring if the remaining target becomes negative.

### Explanation

- Start from number `1`.
- Iterate through all remaining numbers.
- Choose the current number.
- Recurse with:
  - remaining target
  - remaining count (`k-1`)
  - next number (`j+1`)
- Backtrack after recursion.
- Store the combination when exactly `k` numbers are chosen and the remaining target becomes `0`.

---

## Algorithm

1. Start recursion from `1`.
2. Stop if:
   - `k == 0`
   - target becomes negative
   - numbers exceed `9`
3. Iterate through remaining numbers.
4. Choose the current number.
5. Recurse with updated values.
6. Backtrack.

---

## Complexity

- **Time:** Exponential
- **Space:** `O(K)`

---

# Code

```cpp
class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& curr, int k, int n, int i){
        if(k==0){
            if(n==0){
                ans.push_back(curr);
                return;
            }
            return;
        }
        if(n<0 || i>9){
            return;
        }
        for(int j=i;j<=9;j++){
            if(j>n){
                break;
            }
            curr.push_back(j);
            solve(ans,curr,k-1,n-j,j+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(ans,curr,k,n,1);
        return ans;
    }
};
```

---

# Interview Discussion

- Why use `j + 1`?
  - Every number can be used only once.
- Why use `break` when `j > target`?
  - Remaining numbers are even larger.

---

# What I Learned ⭐

- Same recursion template as **Combination Sum II**.
- Candidates are generated (`1...9`) instead of coming from an array.