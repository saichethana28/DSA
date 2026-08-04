# Counting Bits

## Problem Statement

Given an integer `n`, return an array `ans` of length `n + 1` such that:

```
ans[i] = number of set bits in the binary representation of i
```

for every `0 <= i <= n`.

### Example 1

**Input**
```
n = 2
```

**Output**
```
[0,1,1]
```

**Explanation**

```
0 -> 0     -> 0 set bits
1 -> 1     -> 1 set bit
2 -> 10    -> 1 set bit
```

---

### Example 2

**Input**
```
n = 5
```

**Output**
```
[0,1,1,2,1,2]
```

**Explanation**

```
0 -> 000 -> 0

1 -> 001 -> 1

2 -> 010 -> 1

3 -> 011 -> 2

4 -> 100 -> 1

5 -> 101 -> 2
```

---

# Brute Force Approach

## Approach

For every number from `0` to `n`:

- Count its set bits using bit manipulation.
- Store the count in the answer array.

## Code

```cpp
class Solution {
public:

    int countSetBits(int n){

        int count = 0;

        while(n){

            if(n & 1)
                count++;

            n >>= 1;
        }

        return count;
    }

    vector<int> countBits(int n) {

        vector<int> ans;

        for(int i = 0; i <= n; i++)
            ans.push_back(countSetBits(i));

        return ans;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(N log N)`
- **Space Complexity:** `O(N)`

---

# Optimal Approach

## Key Observation

Instead of counting the set bits for every number independently,

we can reuse the answer of a previously computed number.

Observe:

```
5 = 101

5 >> 1 = 10 = 2
```

The binary representation changes as:

```
101

↓

10
```

Right shifting removes the last bit.

Therefore,

```
Number of set bits in 5

=

Number of set bits in 2

+

Last Bit
```

The last bit is simply:

```
5 & 1 = 1
```

Hence,

```
dp[5] = dp[2] + 1
```

Similarly,

```
6 = 110

6 >> 1 = 3

dp[6] = dp[3] + 0
```

Generalizing,

```
dp[i] = dp[i >> 1] + (i & 1)
```

where

- `i >> 1` removes the last bit.
- `i & 1` tells whether the removed bit was `1` or `0`.

## Approach

- Create a DP array of size `n + 1`.
- Initialize:

```
dp[0] = 0
```

- For every number from `1` to `n`:

```
dp[i] = dp[i >> 1] + (i & 1)
```

- Return the DP array.

## Code

```cpp
class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> dp(n + 1);

        dp[0] = 0;

        for(int i = 1; i <= n; i++)
            dp[i] = dp[i >> 1] + (i & 1);

        return dp;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(N)`

---

# Interview Notes

- One of the most common Dynamic Programming + Bit Manipulation problems.
- The recurrence

```
dp[i] = dp[i >> 1] + (i & 1)
```

is worth remembering because it appears in many interview discussions.
- The key idea is **reusing previously computed answers instead of recalculating set bits every time**.

---

# What I Learned ⭐

- Right shifting a number removes its least significant bit.
- The least significant bit can be obtained using `i & 1`.
- The number of set bits in a number equals the set bits of its half (`i >> 1`) plus the contribution of its last bit.
- Dynamic Programming can significantly optimize repeated bit-counting computations from `O(N log N)` to `O(N)`.