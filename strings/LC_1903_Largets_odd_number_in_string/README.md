# LC 1903 - Largest Odd Number in String

## Problem

Given a numeric string, return the **largest-valued odd integer** that is a non-empty substring of the string. If no odd integer exists, return an empty string.

---

## Key Observation 💡

To obtain the **largest-valued** odd substring:

* The substring should always start from index `0`.
* We only need to find the **last odd digit** in the string.
* Once we find it, return the substring from index `0` to that position.

**Reason:** Removing digits from the front decreases the value, so the longest possible prefix ending at an odd digit gives the largest odd number.

---

## Approach

1. Traverse the string from **right to left**.
2. Check whether the current digit is odd.
3. The first odd digit encountered is the last odd digit in the string.
4. Return the substring from index `0` to that index.
5. If no odd digit exists, return an empty string.

---

## Example

**Input**

```text
num = "35420"
```

Traverse from the end:

```text
0 ❌
2 ❌
4 ❌
5 ✅
```

Return:

```text
"35"
```

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)` (excluding the returned string)

---

## What I Learned ⭐

* Sometimes the solution comes from a simple observation rather than a complex algorithm.
* To maximize a numeric substring, keep the prefix as long as possible.
* Traversing from the end helps find the answer in a single pass.
