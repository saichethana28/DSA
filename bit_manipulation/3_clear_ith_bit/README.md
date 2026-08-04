# Clear ith Bit

## Problem Statement

Given an integer `n` and an index `i` (0-indexed from the right), clear the `i`th bit of the number and return the updated number.

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

Mask = ~(1 << 2)

1 << 2 = 0100
~0100   = 1011

1101
1011
----
1001 = 9
```

The 2nd bit is cleared from `1` to `0`.

---

# Brute Force Approach

## Approach

- Convert the number into its binary representation.
- Change the `i`th bit to `0`.
- Convert the binary representation back to decimal.

## Code

```cpp
int clearBit(int n, int i) {
    vector<int> bits;

    while (n) {
        bits.push_back(n % 2);
        n /= 2;
    }

    while (bits.size() <= i)
        bits.push_back(0);

    bits[i] = 0;

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

To clear the `i`th bit, first create a mask having all bits set except the `i`th bit.

```
mask = ~(1 << i)
```

Performing AND with this mask:

- `1 & 0 = 0`
- `0 & 0 = 0`
- All other bits remain unchanged because they are ANDed with `1`.

Therefore,

```
n & ~(1 << i)
```

clears only the required bit.

## Approach

- Create a mask using left shift.
- Invert the mask using the NOT operator.
- Perform bitwise AND with the number.
- Return the updated number.

## Code

```cpp
int clearBit(int n, int i) {
    return n & ~(1 << i);
}
```

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)**

---

# Interview Notes

- Clearing bits is commonly used while removing flags in bitmasking.
- Remember to use parentheses:

```cpp
n & ~(1 << i)
```

Writing `~1 << i` gives a different result due to operator precedence.

---

# What I Learned ⭐

- How to create a mask with all bits set except one.
- Why AND with the inverted mask clears exactly one bit.
- Importance of operator precedence while using bitwise operators.