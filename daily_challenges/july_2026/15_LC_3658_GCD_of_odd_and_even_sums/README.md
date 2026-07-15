# LC 3658 - GCD of Odd and Even Sums

## Problem

Given an integer `n`, compute:

- `sumOdd` = Sum of the first `n` positive odd numbers.
- `sumEven` = Sum of the first `n` positive even numbers.

Return the **GCD(sumOdd, sumEven)**.

---

# Brute Force Approach

## Idea

Generate the first `n` odd and even numbers, compute their sums, and then find their GCD using Euclid's Algorithm.

### Algorithm

1. Traverse from `1` to `n`.
2. Add `(2*i - 1)` to `sumOdd`.
3. Add `(2*i)` to `sumEven`.
4. Compute `gcd(sumOdd, sumEven)`.

### Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

### Code

```cpp
class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    int gcdOfOddEvenSums(int n) {

        int sumOdd = 0;
        int sumEven = 0;

        for (int i = 1; i <= n; i++) {
            sumOdd += (2 * i - 1);
            sumEven += (2 * i);
        }

        return gcd(sumOdd, sumEven);
    }
};
```

---

# Better Approach

## Key Observation

The sums follow well-known mathematical formulas:

- Sum of first `n` odd numbers:

```
1 + 3 + 5 + ... = n²
```

- Sum of first `n` even numbers:

```
2 + 4 + 6 + ... = n(n + 1)
```

So,

```
Answer = GCD(n², n(n+1))
```

### Algorithm

1. Compute:
   - `sumOdd = n²`
   - `sumEven = n(n+1)`
2. Return their GCD.

### Complexity

- **Time Complexity:** `O(log n)` (Euclid's Algorithm)
- **Space Complexity:** `O(1)`

### Code

```cpp
class Solution {
public:
    int gcdOfOddEvenSums(int n) {

        int sumOdd = n * n;
        int sumEven = n * (n + 1);

        return __gcd(sumOdd, sumEven);
    }
};
```

---

# Optimal Approach (Mathematical Observation)

## Key Observation

Using the formulas:

```
sumOdd = n²

sumEven = n(n + 1)
```

Taking GCD,

```
GCD(n², n(n+1))
```

Factor out `n`:

```
= n × GCD(n, n+1)
```

Since consecutive numbers are always coprime,

```
GCD(n, n+1) = 1
```

Therefore,

```
GCD(sumOdd, sumEven) = n
```

### Algorithm

1. Return `n`.

### Complexity

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

### Code

```cpp
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};
```

---

# Interview Discussion

- Start with the mathematical formulas for odd and even sums.
- Simplify the GCD expression algebraically instead of directly computing it.
- Recognizing number theory identities can reduce an `O(n)` solution to `O(1)`.

---

# What I Learned ⭐

- Sum of first `n` odd numbers is `n²`.
- Sum of first `n` even numbers is `n(n+1)`.
- Consecutive integers are always coprime.
- Factoring common terms before computing GCD often simplifies the problem.
- Mathematical observations can completely eliminate computation.