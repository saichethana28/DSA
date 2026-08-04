# Set ith Bit

## Problem Statement

Given an integer `n` and an index `i` (0-indexed from the right), set the `i`th bit of the number and return the updated number.

### Example

**Input**
```
n = 9
i = 1
```

**Output**
```
11
```

**Explanation**

```
9  = 1001
Mask = 0010

1001
0010
----
1011 = 11
```

The 1st bit is set to `1`.

---

# Brute Force Approach

## Approach

- Convert the number into its binary representation.
- Change the `i`th bit to `1`.
- Convert the binary representation back to decimal.

## Code

```cpp
int setBit(int n, int i) {
    vector<int> bits;

    while (n) {
        bits.push_back(n % 2);
        n /= 2;
    }

    while (bits.size() <= i)
        bits.push_back(0);

    bits[i] = 1;

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

To set the `i`th bit, create a mask having only the `i`th bit set.

```
mask = (1 << i)
```

Using the OR (`|`) operation:

- `0 | 1 = 1`
- `1 | 1 = 1`

Therefore,

```
n | (1 << i)
```

always sets the `i`th bit without affecting any other bits.

## Approach

- Create a mask using left shift.
- Perform bitwise OR with the number.
- Return the updated number.

## Code

```cpp
int setBit(int n, int i) {
    return n | (1 << i);
}
```

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---

# Interview Notes

- OR (`|`) is commonly used for setting bits.
- Setting an already set bit does not change the number.
- This operation is frequently used in bitmasking and state compression problems.

---

# What I Learned ⭐

- How to create a bit mask using `1 << i`.
- Why the OR operation always sets a bit to `1`.
- How to modify a specific bit without affecting the remaining bits.