# Odd or Even using Bit Manipulation

## Problem Statement

Given an integer `n`, determine whether it is **Odd** or **Even** using bit manipulation.

### Example 1

**Input**
```
n = 13
```

**Output**
```
Odd
```

**Explanation**

```
13 = 1101
```

The least significant bit (0th bit) is `1`, so the number is **Odd**.

---

### Example 2

**Input**
```
n = 10
```

**Output**
```
Even
```

**Explanation**

```
10 = 1010
```

The least significant bit (0th bit) is `0`, so the number is **Even**.

---

# Brute Force Approach

## Approach

A number is:

- **Even** if it is divisible by `2`.
- **Odd** otherwise.

We can simply use the modulo (`%`) operator.

## Code

```cpp
string oddEven(int n) {
    if (n % 2 == 0)
        return "Even";
    return "Odd";
}
```

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---

# Optimal Approach

## Key Observation

The **least significant bit (0th bit)** determines whether a number is odd or even.

```
Even Number

1010
   ^
   0
```

```
Odd Number

1101
   ^
   1
```

Checking

```
n & 1
```

returns:

- `1` → Odd
- `0` → Even

This works because the 0th bit contributes the value `1` in binary representation.

## Approach

- Perform a bitwise AND with `1`.
- If the result is non-zero, return `"Odd"`.
- Otherwise, return `"Even"`.

## Code

```cpp
string oddEven(int n) {
    if (n & 1)
        return "Odd";
    return "Even";
}
```

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---

# Interview Notes

- One of the most common introductory bit manipulation tricks.
- Faster and cleaner than using the modulo operator in bit manipulation problems.
- The result depends only on the least significant bit.

---

# What I Learned ⭐

- The 0th bit determines the parity of a number.
- If the least significant bit is `1`, the number is **Odd**.
- If the least significant bit is `0`, the number is **Even**.
- `n & 1` is a simple and efficient way to check whether a number is odd or even.