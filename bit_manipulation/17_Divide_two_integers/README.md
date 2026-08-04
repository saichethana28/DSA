# Divide Two Integers

## Problem Statement

Given two integers, `dividend` and `divisor`, divide two integers **without using multiplication (`*`), division (`/`), or modulo (`%`) operators**.

Return the quotient after dividing `dividend` by `divisor`.

The fractional part should be truncated towards zero.

If the quotient exceeds the 32-bit signed integer range:

```
[-2³¹, 2³¹ - 1]
```

return the corresponding limit.

### Example 1

**Input**
```
dividend = 10
divisor = 3
```

**Output**
```
3
```

**Explanation**

```
10 / 3 = 3.333...

After truncating towards zero,

Answer = 3
```

---

### Example 2

**Input**
```
dividend = 7
divisor = -3
```

**Output**
```
-2
```

**Explanation**

```
7 / (-3) = -2.333...

After truncating towards zero,

Answer = -2
```

---

# Brute Force Approach

## Approach

Repeatedly subtract the divisor from the dividend until the remaining value becomes smaller than the divisor.

The number of successful subtractions gives the quotient.

Finally, assign the correct sign to the answer.

## Code

```cpp
int divide(int dividend, int divisor) {

    long long dvd = abs((long long)dividend);
    long long dvs = abs((long long)divisor);

    int quotient = 0;

    while(dvd >= dvs){
        dvd -= dvs;
        quotient++;
    }

    if((dividend < 0) ^ (divisor < 0))
        quotient = -quotient;

    return quotient;
}
```

## Complexity Analysis

- **Time Complexity:** `O(dividend / divisor)`
- **Space Complexity:** `O(1)`

---

# Optimal Approach

## Key Observation

Instead of subtracting the divisor one time in every iteration,

subtract the **largest possible multiple of the divisor**.

A multiple of the divisor can be generated efficiently using **left shift**.

```
divisor << k

=

divisor × 2ᵏ
```

Keep doubling the divisor until it becomes larger than the remaining dividend.

Subtract that largest multiple and add the corresponding power of two to the quotient.

Repeat until the remaining dividend becomes smaller than the divisor.

Example:

```
Dividend = 43

Divisor = 5
```

Largest multiples:

```
5

10

20

40 ✓
```

Subtract:

```
43 - 40 = 3
```

Quotient:

```
2³ = 8
```

Since the remaining value is less than the divisor,

the final answer is

```
8
```

instead of performing eight separate subtractions.

## Approach

- Convert both numbers to positive `long long` values.
- Keep subtracting the largest shifted divisor.
- Add the corresponding power of two to the quotient.
- Apply the correct sign.
- Handle the overflow case separately.

## Code

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long quotient = 0;

        while(dvd >= dvs){

            int shift = 0;

            while(dvd >= (dvs << (shift + 1)))
                shift++;

            quotient += (1LL << shift);
            dvd -= (dvs << shift);
        }

        if((dividend < 0) ^ (divisor < 0))
            quotient = -quotient;

        return (int)quotient;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(log² N)`  
  (Outer loop runs logarithmically, and the inner loop finds the maximum valid shift.)

- **Space Complexity:** `O(1)`

---

# Interview Notes

- This problem tests understanding of **bit manipulation**, not arithmetic.
- Left shift is used to efficiently compute powers of two.

```
x << k

=

x × 2ᵏ
```

- Always use `long long` to avoid overflow.
- Handle the special case:

```cpp
INT_MIN / -1
```

because the answer exceeds the 32-bit signed integer range.
- This is considered one of the harder bit manipulation interview problems.

---

# What I Learned ⭐

- Left shifting can efficiently generate multiples of a number.
- Repeated doubling is much faster than repeated subtraction.
- Overflow handling is an important part of integer arithmetic problems.
- Bit manipulation can replace arithmetic operators in optimization problems.
- Many seemingly mathematical problems can be solved efficiently using binary representation.