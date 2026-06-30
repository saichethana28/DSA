# 1358. Number of Substrings Containing All Three Characters

## Problem

Given a string containing only `'a'`, `'b'`, and `'c'`, count the number of substrings that contain **at least one occurrence of all three characters**.

---

## Brute Force Approach

* Start every substring from index `i`.
* Extend the substring by moving `j`.
* Maintain the frequency of `a`, `b`, and `c`.
* If all three characters are present, increment the answer.

**Time Complexity:** `O(n²)` → TLE for `n = 5 × 10⁴`.

---

## Key Observation

If a substring `s[left...right]` already contains all three characters, then **every substring formed by extending `right` is also valid**.

Example:

```text
abc    ✅
abca   ✅
abcab  ✅
abcabc ✅
```

Instead of counting each substring separately,

```cpp
ans += n - right;
```

This counts all valid substrings starting at `left` and ending from `right` to `n-1`.

---

## Optimal Approach (Sliding Window)

* Expand the window by moving `right`.
* Store the frequency of each character.
* Whenever the window contains `'a'`, `'b'`, and `'c'`:

  * Add `n - right` to the answer.
  * Remove the leftmost character.
  * Move `left`.
* Keep shrinking while the window remains valid.

---

## Why `while` Instead of `if`?

A window can remain valid even after removing the leftmost character.

Example:

```text
aaabc

aaabc ✅
aabc  ✅
abc   ✅
bc    ❌
```

So shrinking only once misses valid substrings.

---

## Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`

---

## What I Learned

* First solve the problem using brute force.
* Look for repeated work that can be avoided.
* If a valid window stays valid after extending to the right, count all such substrings together using `n - right`.
* In sliding window problems, don't think **"How many times should I move left?"**
* Instead, think **"Move left while the window satisfies the condition."**
