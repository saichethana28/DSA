# Find the Rightmost Set Bit

## Problem Statement

Given an integer `n`, find the value of its **rightmost set bit**.

The rightmost set bit is the first bit having value `1` when traversing from the least significant bit (right side).

### Example 1

**Input**
```
n = 12
```

**Output**
```
4
```

**Explanation**

```
12 = 1100₂
```

The rightmost set bit is at the 3rd position from the right, having a value of **4**.

---

### Example 2

**Input**
```
n = 10
```

**Output**
```
2
```

**Explanation**

```
10 = 1010₂
```

The rightmost set bit has a value of **2**.

---

# Brute Force Approach

## Approach

- Traverse every bit from the least significant bit.
- Find the first bit that is set.
- Return its corresponding value.

## Code

```cpp
int rightMostSetBit(int n) {
    int bit = 1;

    while ((n & 1) == 0) {
        n >>= 1;
        bit <<= 1;
    }

    return bit;
}
```

## Complexity Analysis

- **Time Complexity:** `O(log N)`
- **Space Complexity:** `O(1)`

---

# Optimal Approach

## Key Observation

The expression

```
n & (-n)
```

extracts the rightmost set bit.

Why?

Negative numbers are represented using **2's Complement**.

To obtain `-n`:

1. Invert all the bits.
2. Add `1`.

When `n` is ANDed with `-n`, every bit except the rightmost set bit gets cancelled.

Example:

```
n = 12

1100
```

```
-n

0100
```

```
1100
0100
----
0100
```

The answer is **4**.

## Approach

- Compute:

```
n & (-n)
```

- Return the result.

## Code

```cpp
int rightMostSetBit(int n) {
    return n & (-n);
}
```

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---

# Interview Notes

- One of the most useful bit manipulation tricks.
- Frequently used in:
  - Single Number III
  - Bitmasking
  - Binary Indexed Tree (Fenwick Tree)
  - Lowbit operations
- In C++, be careful with `INT_MIN` because negating it in a signed `int` can cause overflow. If needed, use an unsigned type or a wider integer type.

---

# What I Learned ⭐

- The rightmost set bit is the first `1` encountered from the least significant side.
- `n & (-n)` extracts the rightmost set bit in constant time.
- `-n` is obtained using the **2's Complement** representation.
- This trick is extremely useful for partitioning numbers in XOR-based interview problems like **Single Number III**.