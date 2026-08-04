# Reverse Bits

## Problem Statement

Reverse the bits of a given 32-bit unsigned integer and return the reversed integer.

### Example 1

**Input**
```
n = 00000000000000000000000000001011
```

**Output**
```
11010000000000000000000000000000
```

### Example 2

**Input**
```
n = 11111111111111111111111111111101
```

**Output**
```
10111111111111111111111111111111
```

---

# Brute Force Approach

## Approach

Traverse all 32 bits from the most significant bit to the least significant bit.

- If the `i`th bit of the original number is set,
- Set the `(31-i)`th bit in the answer.

This effectively reverses every bit position.

## Code

```cpp
uint32_t reverseBits(uint32_t n) {

    uint32_t ans = 0;

    for(int i = 31; i >= 0; i--) {

        if(n & (1u << i))
            ans |= (1u << (31 - i));
    }

    return ans;
}
```

## Complexity Analysis

- **Time Complexity:** `O(32)` ≈ `O(1)`
- **Space Complexity:** `O(1)`

---

# Optimal Approach

## Key Observation

Instead of explicitly swapping bits,

we directly construct the reversed number.

Whenever the `i`th bit of the original number is set,

we simply set the corresponding mirrored bit `(31-i)` in the answer.

Since an integer contains only 32 bits, this runs in constant time.

## Approach

- Traverse every bit from 31 to 0.
- If the current bit is set,
- Set its mirrored position in the answer.
- Return the constructed number.

## Code

```cpp
uint32_t reverseBits(uint32_t n) {

    uint32_t ans = 0;

    for(int i = 31; i >= 0; i--) {

        if(n & (1u << i))
            ans |= (1u << (31 - i));
    }

    return ans;
}
```

## Complexity Analysis

- **Time Complexity:** `O(32)` ≈ `O(1)`
- **Space Complexity:** `O(1)`

---

# Interview Notes

- Use `1u` (unsigned) instead of `1` to avoid undefined behavior while shifting into the sign bit.
- A common follow-up is:
  > "How would you optimize if this function is called millions of times?"
  The answer is using precomputed lookup tables for every 8-bit block.

---

# What I Learned ⭐

- Bit positions can be mirrored using `(31 - i)`.
- Constructing the answer is simpler than physically swapping bits.
- Unsigned integers should be used while working with all 32 bits.