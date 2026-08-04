# Check if ith Bit is Set

## Problem Statement

Given an integer `n` and an index `i` (0-indexed from the right), determine whether the `i`th bit is set or not.

### Example

**Input**
```
n = 13
i = 2
```

**Output**
```
true
```

**Explanation**

13 in binary is `1101`.

The 2nd bit (0-indexed) is `1`, so the answer is `true`.

---

# Brute Force Approach

## Approach

- Convert the number into its binary representation.
- Check the `i`th bit in the binary string.
- Return whether it is `1`.

## Code

```cpp
bool isSet(int n, int i) {
    string binary = "";
    while (n) {
        binary = char((n % 2) + '0') + binary;
        n /= 2;
    }
    int idx = binary.length() - 1 - i;
    return binary[idx] == '1';
}
```

## Complexity Analysis

- **Time Complexity:** `O(log N)`
- **Space Complexity:** `O(log N)`

---

# Optimal Approach

## Key Observation

To check the `i`th bit, create a mask having only the `i`th bit set.

```
mask = (1 << i)
```

If

```
n & mask
```

is non-zero, then the `i`th bit is set.

## Approach

- Create a mask using left shift.
- Perform bitwise AND with the number.
- If the result is non-zero, the bit is set.

## Code

```cpp
bool isSet(int n, int i) {
    return (n & (1 << i)) != 0;
}
```

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---

# Interview Notes

- One of the most fundamental bit manipulation operations.
- Frequently used in bitmasking and subset generation problems.

---

# What I Learned ⭐

- How to create a bit mask using `1 << i`.
- How the AND operator helps check whether a particular bit is set.
- Why bit manipulation solutions are faster than converting numbers to binary strings.