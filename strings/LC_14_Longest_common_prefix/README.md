# LC 14 - Longest Common Prefix

## Problem

Given an array of strings, find the **longest common prefix** among them. If no common prefix exists, return an empty string.

---

## Approach - Horizontal Scanning

### Thought Process

* Take the first string as the current common prefix.
* Compare it with every other string.
* Store the matching characters until a mismatch occurs.
* Update the current prefix.
* Repeat the process for all strings.

If the prefix becomes empty at any point, return `""` immediately since no common prefix can exist.

---

## Key Observation 💡

The common prefix can only **decrease** as we compare more strings.

So after every comparison, update the prefix and use it for the next string.

---

## Example

**Input**

```text
["flower", "flow", "flight"]
```

Comparison:

```text
flower & flow     -> flow
flow   & flight   -> fl
```

Answer:

```text
"fl"
```

---

## Complexity

* **Time Complexity:** `O(S)`

  where **S** is the total number of characters across all strings.

* **Space Complexity:** `O(S)` (temporary prefix string)

---

## What I Learned ⭐

* Instead of comparing every pair of strings, maintain a running common prefix.
* The common prefix only becomes shorter, never longer.
* If the prefix becomes empty, terminate early.
* Horizontal scanning is a simple and efficient approach for this problem.
