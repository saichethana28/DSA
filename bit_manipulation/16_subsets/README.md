# Subsets

## Problem Statement

Given an integer array `nums` of **unique** elements, return **all possible subsets** (the power set).

The solution set must not contain duplicate subsets. You may return the subsets in any order.

### Example 1

**Input**
```
nums = [1,2,3]
```

**Output**
```
[
 [],
 [1],
 [2],
 [3],
 [1,2],
 [1,3],
 [2,3],
 [1,2,3]
]
```

**Explanation**

For an array of size `3`, there are `2³ = 8` possible subsets.

---

### Example 2

**Input**
```
nums = [0]
```

**Output**
```
[
 [],
 [0]
]
```

---

# Brute Force Approach

## Approach

Use recursion (Backtracking).

For every element, we have two choices:

- Include the current element.
- Exclude the current element.

Recursively explore both possibilities until all elements have been processed.

## Code

```cpp
class Solution {
public:

    vector<vector<int>> ans;
    vector<int> subset;

    void solve(int idx, vector<int>& nums){

        if(idx == nums.size()){
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        solve(idx + 1, nums);

        subset.pop_back();
        solve(idx + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        solve(0, nums);
        return ans;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(N × 2ᴺ)`
- **Space Complexity:** `O(N)` (Recursion Stack)

---

# Optimal Approach (Bit Manipulation)

## Key Observation

Every subset can be represented using a **bitmask**.

For an array of size `n`:

```
Total subsets = 2ⁿ
```

Every number from

```
0

to

2ⁿ - 1
```

represents one subset.

Example:

```
nums = [1,2,3]
```

```
Mask = 000

↓

{}
```

```
Mask = 001

↓

{1}
```

```
Mask = 010

↓

{2}
```

```
Mask = 011

↓

{1,2}
```

```
Mask = 100

↓

{3}
```

and so on.

If the `j`th bit of the mask is set,

include `nums[j]` in the current subset.

## Approach

- Iterate through every mask from `0` to `2ⁿ - 1`.
- For each mask:
    - Traverse every bit.
    - If the bit is set, include the corresponding element.
- Store the generated subset.

## Code

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> ans;

        for(int mask = 0; mask < (1 << n); mask++){

            vector<int> subset;

            for(int j = 0; j < n; j++){

                if(mask & (1 << j))
                    subset.push_back(nums[j]);
            }

            ans.push_back(subset);
        }

        return ans;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(N × 2ᴺ)`
- **Space Complexity:** `O(1)` (excluding output)

---

# Interview Notes

- This is one of the most common applications of **Bit Manipulation**.
- Every integer from `0` to `2ⁿ - 1` uniquely represents a subset.
- Bitmasking avoids recursion and is often preferred when `n` is small (typically `n ≤ 20`).
- A common interview follow-up is to generate combinations, permutations, or subsets satisfying certain constraints using bitmasks.

---

# What I Learned ⭐

- Every subset can be represented by a binary number.
- The `j`th bit determines whether `nums[j]` belongs to the current subset.
- There are exactly `2ⁿ` subsets for an array of size `n`.
- Bitmasking provides an elegant iterative alternative to recursion for subset generation.