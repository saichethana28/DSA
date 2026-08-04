# Bitwise AND of Numbers Range

## Problem Statement

Given two integers `left` and `right`, return the bitwise **AND** of every number in the inclusive range `[left, right]`.

### Example 1

**Input**
```
left = 5
right = 7
```

**Output**
```
4
```

**Explanation**

```
5 = 101
6 = 110
7 = 111

101
110
111
---
100 = 4
```

---

### Example 2

**Input**
```
left = 0
right = 0
```

**Output**
```
0
```

---

# Brute Force Approach

## Approach

- Initialize the answer with `left`.
- Traverse every number from `left + 1` to `right`.
- Perform bitwise AND with the current answer.
- Return the final answer.

## Code

```cpp
int rangeBitwiseAnd(int left, int right) {

    int ans = left;

    for(int i = left + 1; i <= right; i++)
        ans &= i;

    return ans;
}
```

## Complexity Analysis

- **Time Complexity:** `O(right - left)`
- **Space Complexity:** `O(1)`

---

# Optimal Approach

## Key Observation

Whenever numbers change within a range, the bits that differ eventually become `0` after performing the AND operation.

Only the **common leftmost prefix** of all numbers survives.

Example:

```
left  = 26 = 11010
right = 30 = 11110
```

Observe the bits:

```
11010
11011
11100
11101
11110
```

The last three bits keep changing.

After ANDing all numbers:

```
11000
```

Only the common prefix `11` survives.

We can find this common prefix by repeatedly right shifting both numbers until they become equal.

```
26 = 11010
30 = 11110

↓

1101
1111

↓

110
111

↓

11
11
```

Now both numbers are equal.

Since we shifted three times, shift the answer back three positions.

```
11 << 3 = 11000
```

which is `24`.

## Approach

- Initialize a counter to `0`.
- While `left != right`:
    - Right shift both numbers.
    - Increment the counter.
- Once both numbers become equal, shift the result back by the same count.

## Code

```cpp
int rangeBitwiseAnd(int left, int right) {

    int shifts = 0;

    while(left != right) {
        left >>= 1;
        right >>= 1;
        shifts++;
    }

    return left << shifts;
}
```

## Complexity Analysis

- **Time Complexity:** `O(32)` ≈ `O(1)`
- **Space Complexity:** `O(1)`

---

# Interview Notes

- One of the most elegant bit manipulation interview problems.
- Instead of ANDing every number, think about **which bits can never survive**.
- The common prefix technique is useful in several binary and trie-based problems.
- A common interview hint is:
  > "Which bits remain unchanged throughout the entire range?"

---

# What I Learned ⭐

- In a range of numbers, changing bits eventually become `0` after repeated AND operations.
- Only the common leftmost prefix survives.
- Repeatedly right shifting both numbers until they become equal efficiently finds this common prefix.
- Shifting the common prefix back restores the final answer.