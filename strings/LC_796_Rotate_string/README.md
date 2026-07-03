# LC 796 - Rotate String

## Problem

Given two strings `s` and `goal`, determine whether `goal` can be obtained by performing zero or more **left rotations** on `s`.

A left rotation moves the first character of the string to the end.

---

## Approach 1 - Brute Force

### Thought Process

* If the lengths of the two strings are different, they can never be rotations of each other.
* Rotate the string one position at a time.
* After every rotation, compare it with `goal`.
* If they become equal, return `true`.
* If all possible rotations are checked and no match is found, return `false`.

### Complexity

* **Time Complexity:** `O(n²)`

  * `n` rotations, each requiring string construction/comparison.
* **Space Complexity:** `O(n)`

---

## Key Observation 💡

If a string is rotated, its characters wrap around.

For example,

```text
s = "abcde"

s + s = "abcdeabcde"
```

All possible rotations of `s` appear as contiguous substrings inside `s + s`.

Example:

```text
abcdeabcde

abcde
 bcdea
  cdeab
   deabc
    eabcd
```

So instead of generating every rotation, we only need to check whether `goal` is a substring of `s + s`.

---

## Approach 2 - Optimized

1. Check whether the lengths are equal.
2. Concatenate the string with itself.
3. Search for `goal` inside `s + s`.
4. If found, return `true`; otherwise return `false`.

---

## Example

**Input**

```text
s = "abcde"
goal = "cdeab"
```

Concatenated string:

```text
abcdeabcde
```

Since `"cdeab"` is a substring of `"abcdeabcde"`, the answer is:

```text
true
```

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

---

## What I Learned ⭐

* Sometimes constructing all possible answers is unnecessary.
* String concatenation can naturally represent every rotation.
* `find()` is a powerful STL function for substring search.
* Always look for mathematical or structural observations before simulating every operation.
