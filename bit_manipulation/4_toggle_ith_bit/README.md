# Toggle ith Bit

## Problem Statement

Given an integer `n` and an index `i` (0-indexed from the right), toggle the `i`th bit of the number and return the updated number.

Toggling means:
- If the bit is `0`, change it to `1`.
- If the bit is `1`, change it to `0`.

### Example

**Input**
```
n = 13
i = 2
```

**Output**
```
9
```

**Explanation**

```
13 = 1101

Mask = 0100

1101
0100
----
1001 = 9
```

The 2nd bit is toggled from `1` to `0`.

---

# Brute Force Approach

## Approach

- Convert the number into its binary representation.
- Check the `i`th bit.
- If it is `0`, make it `1`.
- If it is `1`, make it `0`.
- Convert the binary representation back to decimal.

## Code

```cpp
int toggleBit(int n, int i) {
    vector<int> bits;

    while (n) {
        bits.push_back(n % 2);
        n /= 2;
    }

    while (bits.size() <= i)
        bits.push_back(0);

    bits[i] = 1 - bits[i];

    int ans = 0;
    int power = 1;

    for (int bit : bits) {
        ans += bit * power;
        power *= 2;
    }

    return ans;
}
```

## Complexity Analysis

- **Time Complexity:** `O(log N)`
- **Space Complexity:** `O(log N)`

---

# Optimal Approach

## Key Observation

The XOR (`^`) operator flips a bit whenever it is XORed with `1`.

```
0 ^ 1 = 1
1 ^ 1 = 0
```

Create a mask having only the `i`th bit set.

```
mask = (1 << i)
```

Then perform:

```
n ^ mask
```

Only the `i`th bit changes, while every other bit remains unchanged.

## Approach

- Create a mask using left shift.
- Perform bitwise XOR with the number.
- Return the updated number.

## Code

```cpp
int toggleBit(int n, int i) {
    return n ^ (1 << i);
}
```

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---

# Interview Notes

- XOR is one of the most important bitwise operators.
- It is commonly used for toggling bits, swapping numbers without extra space, finding unique elements, and many bitmasking problems.
- Toggling the same bit twice restores the original number.

---

# What I Learned ⭐

- XOR with `1` flips a bit, while XOR with `0` leaves it unchanged.
- A bit mask can be used to toggle any desired bit in constant time.
- XOR is one of the most frequently used operations in interview bit manipulation problems.