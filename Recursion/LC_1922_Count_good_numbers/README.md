# LC 1922 - Count Good Numbers

## Problem

A digit string of length `n` is **good** if:

- Digits at **even indices** are even (`0, 2, 4, 6, 8`).
- Digits at **odd indices** are prime (`2, 3, 5, 7`).

Return the total number of good digit strings modulo `10⁹ + 7`.

---

# Brute Force Approach

## Idea

Generate every possible digit string of length `n` and check whether it satisfies the given conditions.

### Algorithm

1. Generate all possible strings of length `n`.
2. Check every position:
   - Even index → Even digit.
   - Odd index → Prime digit.
3. Count all valid strings.

### Complexity

- **Time Complexity:** `O(10ⁿ)`
- **Space Complexity:** `O(n)`

> This approach is impossible for `n` up to `10¹⁵`.

---

# Better Approach

## Key Observation

Instead of generating all strings:

- Every **even index** has **5 choices**:
  ```
  0, 2, 4, 6, 8
  ```

- Every **odd index** has **4 choices**:
  ```
  2, 3, 5, 7
  ```

Therefore,

```
Answer = 5^(Even Positions) × 4^(Odd Positions)
```

For a string of length `n`:

```
Even Positions = (n + 1) / 2

Odd Positions = n / 2
```

The remaining challenge is computing large powers efficiently.

---

# Optimal Approach (Binary Exponentiation)

## Key Observation

- Computing `5^n` or `4^n` using repeated multiplication takes `O(n)` time.
- Binary Exponentiation reduces the exponent by half at every recursive call.
- If the exponent is even:
  ```
  xⁿ = (xⁿ⁄²)²
  ```
- If the exponent is odd:
  ```
  xⁿ = (xⁿ⁄²)² × x
  ```
- Perform every multiplication modulo `10⁹ + 7` to avoid overflow.

### Algorithm

1. Count:
   - Even positions = `(n + 1) / 2`
   - Odd positions = `n / 2`
2. Compute:
   - `5^(even)` using Binary Exponentiation.
   - `4^(odd)` using Binary Exponentiation.
3. Multiply both results modulo `10⁹ + 7`.
4. Return the answer.

### Complexity

- **Time Complexity:** `O(log n)`
- **Space Complexity:** `O(log n)` (Recursion Stack)

### Code

```cpp
class Solution {
public:
    const int MOD = 1000000007;

    int power(int base, long long exp) {

        if (exp == 0)
            return 1;

        int half = power(base, exp / 2);

        if (exp % 2 == 0)
            return (1LL * half * half) % MOD;

        return (1LL * base * half % MOD * half) % MOD;
    }

    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n - even;

        int evenWays = power(5, even);
        int oddWays = power(4, odd);

        return (1LL * evenWays * oddWays) % MOD;
    }
};
```

---

# Interview Discussion

- The key observation is counting the number of choices at each position instead of generating strings.
- Binary Exponentiation is required because `n` can be as large as `10¹⁵`.
- Always perform multiplications using `1LL` before taking modulo to avoid integer overflow.

---

# What I Learned ⭐

- Count choices instead of generating all possibilities whenever possible.
- Binary Exponentiation efficiently computes large powers in `O(log n)`.
- Apply modulo after every multiplication to prevent overflow.
- The multiplication principle (`choices₁ × choices₂ × ...`) is useful in counting problems.
- Large constraints often hint at using mathematical observations instead of simulation.