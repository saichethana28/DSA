# LC 50 - Pow(x, n)

## Problem

Implement `pow(x, n)`, which returns `xⁿ`, where:

- `x` is a floating-point number.
- `n` is an integer (positive, negative, or zero).

---

# Brute Force Approach

## Idea

Multiply `x` exactly `n` times. If `n` is negative, compute the reciprocal by converting `x = 1/x` and making `n` positive.

### Algorithm

1. If `n < 0`, convert `x = 1/x` and `n = -n`.
2. Initialize the answer as `1`.
3. Multiply `x` exactly `n` times.
4. Return the final answer.

### Complexity

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(1)`

### Code

```cpp
class Solution {
public:
    double myPow(double x, int n) {

        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double ans = 1;

        while (N--) {
            ans *= x;
        }

        return ans;
    }
};
```

---

# Optimal Approach (Binary Exponentiation)

## Key Observation

- Multiplying `x` repeatedly is inefficient for large exponents.
- The exponent can be reduced by half at every recursive call.
- If `n` is even:
  - `xⁿ = (xⁿ⁄²)²`
- If `n` is odd:
  - `xⁿ = (xⁿ⁄²)² × x`
- Negative powers are handled by converting `x = 1/x` and making the exponent positive.

### Algorithm

1. Store the exponent in a `long long`.
2. If the exponent is negative:
   - Convert `x = 1/x`.
   - Make the exponent positive.
3. Base case: if exponent is `0`, return `1`.
4. Recursively compute `half = myPow(x, n/2)`.
5. If the exponent is even, return `half × half`.
6. Otherwise, return `half × half × x`.

### Complexity

- **Time Complexity:** `O(log N)`
- **Space Complexity:** `O(log N)` (Recursion Stack)

### Code

```cpp
class Solution {
public:
    double myPow(double x, int n) {

        long long N = n;

        if (N < 0) {
            N = -N;
            x = 1 / x;
        }

        if (N == 0)
            return 1;

        double half = myPow(x, N / 2);

        if (N % 2 == 0)
            return half * half;

        return half * half * x;
    }
};
```

---

# Interview Discussion

- Binary Exponentiation is the expected optimal solution.
- Store the recursive result (`half`) once instead of computing it twice.
- Use `long long` before negating the exponent to safely handle `INT_MIN`.

---

# What I Learned ⭐

- Binary Exponentiation is a Divide & Conquer technique.
- Halving the exponent reduces the time complexity to `O(log N)`.
- Handle negative powers before recursion.
- Always use `long long` while negating `INT_MIN`.
- Reusing recursive results avoids unnecessary computations.