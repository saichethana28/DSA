# Check if There Exists a Subsequence with Sum K

## Problem

Given an array `arr` and a target sum `k`, determine whether there exists a subsequence whose sum is equal to `k`.

### Example

**Input**

```text
arr = [10, 1, 2, 7, 6, 1, 5]
k = 8
```

**Output**

```text
true
```

---

# Brute Force Approach

## Idea

Generate every possible subsequence and calculate its sum.

If any subsequence has sum equal to `k`, return `true`.

---

## Algorithm

1. Generate all subsequences.
2. Compute the sum of each subsequence.
3. Return `true` if any subsequence has sum `k`.
4. Otherwise return `false`.

---

## Complexity Analysis

- **Time Complexity:** **O(n × 2ⁿ)**
- **Space Complexity:** **O(n)**

---

# Optimal Approach (Recursion)

## Key Observation

For every element we have two choices:

- Take the element.
- Don't take the element.

If any recursive branch finds a valid subsequence, immediately return `true`.

---

## Algorithm

1. If all elements are processed, check whether `sum == k`.
2. Explore the **Take** branch.
3. If found, return `true`.
4. Otherwise explore the **Don't Take** branch.
5. If both fail, return `false`.

---

## Complexity Analysis

- **Time Complexity:** **O(2ⁿ)**
- **Space Complexity:** **O(n)**

---

## Code

```cpp
class Solution {
public:
    bool solve(vector<int>& arr, int k, int i, int sum) {
        if (i == arr.size())
            return sum == k;

        if (sum > k)
            return false;

        if (solve(arr, k, i + 1, sum + arr[i]))
            return true;

        return solve(arr, k, i + 1, sum);
    }

    bool checkSubsequenceSum(vector<int>& arr, int k) {
        return solve(arr, k, 0, 0);
    }
};
```

---

# Interview Discussion

- Use **bool** because the problem asks whether a valid subsequence exists.
- Return immediately after finding one valid subsequence.
- Pruning using `sum > k` is valid only when all array elements are positive.
- This recursion later becomes **Subset Sum DP**.

---

# What I Learned ⭐

- Learned when to use a **bool** recursive function.
- Understood how early return avoids exploring unnecessary branches.
- Learned the **Take / Don't Take** recursion pattern.
- Realized this recursive solution can later be optimized using Dynamic Programming.