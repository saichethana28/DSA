# Count All Subsequences with Sum K

## Problem

Given an array `arr` and a target sum `k`, count the number of subsequences whose sum equals `k`.

### Example

**Input**

```text
arr = [1, 2, 1]
k = 2
```

**Output**

```text
2
```

---

# Brute Force Approach

## Idea

Generate every possible subsequence and count those whose sum equals `k`.

---

## Algorithm

1. Generate all subsequences.
2. Compute the sum of every subsequence.
3. Increment the count whenever the sum equals `k`.
4. Return the final count.

---

## Complexity Analysis

- **Time Complexity:** **O(n × 2ⁿ)**
- **Space Complexity:** **O(n)**

---

# Optimal Approach (Recursion)

## Key Observation

Every recursive call returns the number of valid subsequences that can be formed from the current state.

The total answer is:

**Take branch + Don't Take branch**

---

## Algorithm

1. If all elements are processed:
   - Return `1` if `sum == k`.
   - Otherwise return `0`.
2. Recursively count subsequences by:
   - Taking the current element.
   - Not taking the current element.
3. Return the sum of both recursive calls.

---

## Complexity Analysis

- **Time Complexity:** **O(2ⁿ)**
- **Space Complexity:** **O(n)**

---

## Code

```cpp
int solve(int n, const vector<int>& arr, int k, int sum, int i) {
    if (i == n)
        return sum == k;

    if (sum > k)
        return 0;

    return solve(n, arr, k, sum + arr[i], i + 1)
         + solve(n, arr, k, sum, i + 1);
}

int countSubsequences(int n, const vector<int>& arr, int k) {
    return solve(n, arr, k, 0, 0);
}
```

---

# Interview Discussion

- Use **int** because every recursive call returns the number of valid subsequences.
- Do not use a global counter unless explicitly required.
- The answer from the current state is:
  - **Take count + Don't Take count**
- This recursion is the foundation of DP with memoization.

---

# What I Learned ⭐

- Learned when to use an **int** recursive function.
- Understood that each recursive call should return its own answer instead of maintaining a global count.
- Learned how recursive answers combine using **left + right**.
- Saw how changing only the return type transforms the recursion pattern.