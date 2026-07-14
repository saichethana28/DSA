# LC 50 - Pow(x, n)

## Problem

Implement the function

```cpp
pow(x, n)
```

which returns

```
xⁿ
```

where:

- `x` is a floating-point number.
- `n` is an integer (can be positive, zero, or negative).

---

# Brute Force Approach

## Idea

Multiply `x` exactly `n` times.

For negative powers,

```
x⁻ⁿ = 1 / xⁿ
```

### Algorithm

1. If `n < 0`
   - Convert `x = 1/x`
   - Make `n` positive.
2. Multiply `x` exactly `n` times.

---

## Code

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

## Complexity

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(1)`

---

# Optimal Approach (Binary Exponentiation)

## Observation

Instead of multiplying `x` exactly `n` times,

we can repeatedly divide the exponent by **2**.

Suppose

```
2¹⁰
```

Instead of

```
2 × 2 × 2 × 2 × 2 × 2 × 2 × 2 × 2 × 2
```

compute

```
2⁵

↓

Square it

↓

(2⁵)² = 2¹⁰
```

Similarly,

```
2⁹

↓

2⁴

↓

Square

↓

Multiply once more by 2
```

This reduces the complexity from

```
O(N)

↓

O(log N)
```

---

# Mathematical Recurrence

If

```
n is even
```

```
xⁿ = (xⁿ⁄²)²
```

If

```
n is odd
```

```
xⁿ = (xⁿ⁄²)² × x
```

---

# Handling Negative Powers

Suppose

```
2⁻³
```

Then

```
2⁻³

=

1 / 2³
```

Instead of handling negatives inside recursion,

convert

```cpp
x = 1 / x;
```

and

```cpp
n = -n;
```

before starting recursion.

To safely handle

```
n = INT_MIN
```

store it in

```cpp
long long
```

before negating.

---

# Code

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

# Complexity

### Time Complexity

At every recursive call,

```
Exponent

↓

n

↓

n/2

↓

n/4

↓

n/8
```

The exponent is halved every time.

Therefore,

```
Time Complexity = O(log N)
```

---

### Space Complexity

Only one recursive call is made at every level.

Maximum recursion depth:

```
log N
```

Hence,

```
Space Complexity = O(log N)
```

---

# Interview Discussion

### Why Binary Exponentiation?

A straightforward solution performs `n` multiplications.

Binary Exponentiation reduces the number of multiplications by repeatedly halving the exponent.

---

### Why use `long long`?

The constraint allows

```
n = -2³¹
```

Negating this value in an `int` causes overflow.

Instead,

```cpp
long long N = n;
```

then

```cpp
N = -N;
```

avoids undefined behavior.

---

### Why only one recursive call?

A common mistake is writing

```cpp
power(x, n/2) * power(x, n/2)
```

This computes the same value twice.

Instead,

store it once.

```cpp
double half = myPow(x, n/2);
```

Then reuse it.

This keeps the complexity

```
O(log N)
```

instead of unnecessarily increasing the work.

---

# What I Learned ⭐

- Binary Exponentiation is a classic **Divide and Conquer** technique.
- Reduce the exponent by half at every recursive call.
- Compute the recursive result only once and reuse it.
- Convert negative powers into positive powers using:

```cpp
x = 1 / x;
n = -n;
```

- Always use `long long` before negating `INT_MIN`.
- Binary Exponentiation is useful in many problems involving:
  - Modular Exponentiation
  - Matrix Exponentiation
  - Fast Power calculations
  - Combinatorics
  - Number Theory

---

# Key Takeaway ⭐

Whenever a problem asks to compute

```
xⁿ
```

or repeatedly apply the same operation `n` times,

ask yourself:

> **Can I divide the exponent into two equal halves?**

If yes, Binary Exponentiation is likely the optimal solution.