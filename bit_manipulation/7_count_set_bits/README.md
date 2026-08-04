# Count Set Bits

## Problem Statement

Given an integer `n`, count the total number of set bits (bits having value `1`) in its binary representation.

Return the count of set bits.

### Example 1

**Input**
```
n = 13
```

**Output**
```
3
```

**Explanation**

```
13 = 1101₂
```

There are **3** set bits.

---

### Example 2

**Input**
```
n = 8
```

**Output**
```
1
```

**Explanation**

```
8 = 1000₂
```

Only one bit is set.

---

# Brute Force Approach

## Approach

Traverse through every bit of the number.

- Check whether the least significant bit is set using `n & 1`.
- If it is set, increment the count.
- Right shift the number by one position.
- Repeat until the number becomes `0`.

## Code

```cpp
int countSetBits(int n) {
    int count = 0;

    while (n) {
        if (n & 1)
            count++;

        n >>= 1;
    }

    return count;
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
n & (n - 1)
```

removes the **rightmost set bit** from the number.

Example:

```
n = 12

1100

n - 1 = 1011

1100
1011
----
1000
```

One set bit is removed.

Repeating this operation continues removing one set bit at a time until the number becomes `0`.

Therefore, the number of iterations is equal to the number of set bits.

## Approach

- Initialize the answer as `0`.
- While `n` is not `0`:
    - Remove the rightmost set bit using:

```
n = n & (n - 1)
```

- Increment the answer.
- Return the answer.

## Code

```cpp
int countSetBits(int n) {
    int count = 0;

    while (n) {
        n = n & (n - 1);
        count++;
    }

    return count;
}
```

## Complexity Analysis

- **Time Complexity:** `O(Number of Set Bits)`
- **Space Complexity:** `O(1)`

---

# Interview Notes

- Brian Kernighan's Algorithm is one of the most important bit manipulation techniques.
- It is much faster than traversing every bit when the number contains only a few set bits.
- The trick `n & (n - 1)` appears in many interview problems like:
  - Power of Two
  - Count Set Bits
  - Number of 1 Bits
  - Single Number variations

---

# What I Learned ⭐

- A number can be traversed bit by bit using right shift.
- The expression `n & (n - 1)` removes the rightmost set bit in every iteration.
- Brian Kernighan's Algorithm runs in **O(number of set bits)**, making it more efficient than checking every bit.
- This is one of the most commonly used bit manipulation tricks in coding interviews.