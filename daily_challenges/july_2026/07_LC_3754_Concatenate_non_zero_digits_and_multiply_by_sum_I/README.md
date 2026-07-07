# LC 3754 - Concatenate Non-Zero Digits and Multiply by Sum I

## Problem

Given an integer `n`:

1. Form a new integer `x` by concatenating all the **non-zero** digits of `n` while preserving their original order.
2. Compute the sum of the digits of `x`.
3. Return:

```text
x × (sum of digits of x)
```

If there are no non-zero digits, then `x = 0`.

---

## My Initial Thought

Traverse the digits of the number from right to left.

Whenever a non-zero digit is found:

* Place it in the correct position of the new number.
* Add the digit to the running sum.

Finally,

```text
Answer = x × sum
```

---

## Key Observation 💡

Since digits are processed from **right to left**, we need a multiplier to place each digit in the correct position.

Instead of using:

```text
10^0
10^1
10^2
...
```

maintain a multiplier:

```text
1
10
100
1000
...
```

After processing every non-zero digit:

```text
multiplier *= 10
```

This avoids unnecessary calls to `pow()` and keeps the implementation simple.

---

## Approach

1. Initialize:

   * `num = 0`
   * `sum = 0`
   * `multiplier = 1`
2. Traverse the digits using modulo (`% 10`).
3. If the digit is non-zero:

   * Append it to `num` using the multiplier.
   * Add it to `sum`.
   * Multiply the multiplier by `10`.
4. Remove the last digit using integer division.
5. Return:

```text
num × sum
```

---

## Example

**Input**

```text
10203004
```

Traversal

```text
Digits processed:
4
3
2
1
```

Constructed number:

```text
1234
```

Digit sum:

```text
1 + 2 + 3 + 4 = 10
```

Answer:

```text
1234 × 10 = 12340
```

---

## Complexity

* **Time Complexity:** `O(d)` where `d` is the number of digits.
* **Space Complexity:** `O(1)`

---

## What I Learned ⭐

* A multiplier variable can replace repeated `pow()` calculations.
* Processing digits from right to left while maintaining a multiplier is an efficient way to reconstruct a number.
* Simple arithmetic operations often lead to cleaner and faster solutions than using library functions.
