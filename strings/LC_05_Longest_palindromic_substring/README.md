# LC 5 - Longest Palindromic Substring

## Problem

Given a string `s`, return the **longest palindromic substring**.

A palindrome is a string that reads the same forward and backward.

---

## My Initial Thought (Brute Force)

Generate every possible substring.

For each substring:

* Check whether it is a palindrome using two pointers.
* If it is a palindrome and its length is greater than the current maximum, update the answer.

### Complexity

* **Time Complexity:** `O(n³)`

  * `O(n²)` substrings
  * `O(n)` palindrome check
* **Space Complexity:** `O(1)`

---

## Key Observation 💡

Every palindrome has a **center**.

There are two possible types of centers:

### Odd-Length Palindrome

The center is a character.

```text id="4rw0j7"
racecar
   ^
```

Example:

```text id="g5zh2r"
aba
```

---

### Even-Length Palindrome

The center lies between two characters.

```text id="rkrp7j"
abba
  ^
```

Example:

```text id="m97ef9"
bb
```

So, for every index `i`, we should check:

* Center at `(i, i)` → Odd-length palindrome
* Center at `(i, i + 1)` → Even-length palindrome

---

## Expand Around Center

For every possible center:

1. Initialize two pointers.
2. Expand outward while:

   * both pointers are inside the string
   * characters are equal
3. Whenever a longer palindrome is found, update the answer.

Repeat this process for both odd and even centers.

---

## Example

**Input**

```text id="pjnh2z"
s = "babad"
```

Checking center at index `2`

```text id="jkblle"
b a b a d
    ^
```

Expansion:

```text id="zjlwmu"
b

↓

aba
```

Longest palindrome found:

```text id="mjlwm1"
"aba"
```

(`"bab"` is also a valid answer.)

---

## Complexity

* **Time Complexity:** `O(n²)`
* **Space Complexity:** `O(1)`

---

## What I Learned ⭐

* Instead of checking every substring, think about the properties of a palindrome.
* Every palindrome expands symmetrically from its center.
* Every index can act as the center of an odd-length palindrome.
* Every gap between two adjacent characters can act as the center of an even-length palindrome.
* Expanding around each center reduces the complexity from `O(n³)` to `O(n²)`.
