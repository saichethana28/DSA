# Power of Two

## Problem Statement

Given an integer `n`, determine whether it is a power of `2`.

A number is said to be a power of `2` if it can be represented as:

```
2^0, 2^1, 2^2, 2^3 ...
```

Return `true` if `n` is a power of `2`, otherwise return `false`.

### Example 1

**Input**
```
n = 16
```

**Output**
```
true
```

**Explanation**

```
16 = 10000₂
```

Only one bit is set, therefore it is a power of `2`.

---

### Example 2

**Input**
```
n = 18
```

**Output**
```
false
```

**Explanation**

```
18 = 10010₂
```

More than one bit is set, so it is not a power of `2`.

---

# Brute Force Approach

## Approach

A power of `2` contains exactly **one set bit**.

- Traverse through every bit.
- Count the number of set bits.
- If the count is exactly `1`, return `true`; otherwise return `false`.

## Code

```cpp
bool isPowerOfTwo(int n) {
    if(n <= 0) return false;

    int count = 0;

    while(n) {
        if(n & 1)
            count++;
        n >>= 1;
    }

    return count == 1;
}
```

## Complexity Analysis

- **Time Complexity:** `O(log N)`
- **Space Complexity:** `O(1)`

---

# Optimal Approach

## Key Observation

For every power of `2`, there is only one set bit.

When we subtract `1`:

```
10000
-    1
------
01111
```

The only set bit becomes `0` and every bit after it becomes `1`.

Therefore,

```
10000
01111
-----
00000
```

So,

```
n & (n - 1)
```

becomes `0`.

For every other number, the result will be non-zero.

## Approach

- If `n <= 0`, return `false`.
- Compute:

```
n & (n - 1)
```

- If the result is `0`, then `n` is a power of `2`.

## Code

```cpp
bool isPowerOfTwo(int n) {
    if(n <= 0)
        return false;

    return (n & (n - 1)) == 0;
}
```

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---

# Interview Notes

- One of the most frequently asked bit manipulation interview questions.
- The trick `n & (n-1)` is also used to remove the rightmost set bit.
- Always remember to check `n > 0`, since `0` is **not** a power of `2`.

---

# What I Learned ⭐

- Every power of `2` has exactly one set bit.
- Subtracting `1` flips the rightmost set bit and sets all lower bits.
- `n & (n - 1)` is an elegant constant-time way to check whether a number is a power of `2`.
- This trick appears in many advanced bit manipulation problems.