# LC 205 - Isomorphic Strings

## Problem

Given two strings `s` and `t`, determine whether they are **isomorphic**.

Two strings are isomorphic if every character in `s` can be replaced with exactly one character in `t`, and **no two different characters map to the same character**.

---

## My First Approach

### Thought Process

* Use a hash map to store the mapping from characters in `s` to characters in `t`.
* If a character is already mapped, verify that it maps to the same character.
* Otherwise, create a new mapping.

### Why It Failed

It only checked:

```text
s → t
```

It did **not** check whether a character in `t` was already assigned to another character in `s`.

Example:

```text
s = "badc"
t = "baba"
```

Mappings become:

```text
b → b
a → a
d → b   ❌
c → a   ❌
```

Two different characters (`b` and `d`) map to `'b'`, and two different characters (`a` and `c`) map to `'a'`.

This violates the one-to-one mapping rule.

---

## Key Observation 💡

A valid isomorphic mapping must satisfy **both** conditions:

1. Every character in `s` always maps to the same character in `t`.
2. Every character in `t` can be mapped from only one character in `s`.

So we need to maintain mappings in **both directions**.

---

## Optimal Approach

Maintain two hash maps:

* `sToT` → stores mapping from `s` to `t`.
* `tToS` → stores mapping from `t` to `s`.

For every index:

* Check if the existing mapping in `sToT` is valid.
* Check if the existing mapping in `tToS` is valid.
* If both are consistent, store/update the mappings.

If any conflict occurs, return `false`.

---

## Example

```text
s = "paper"
t = "title"
```

Mappings:

```text
sToT:
p → t
a → i
e → l
r → e

tToS:
t → p
i → a
l → e
e → r
```

No conflicts occur, so the strings are isomorphic.

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

---

## What I Learned ⭐

* Whenever a problem says **one-to-one mapping**, **unique mapping**, or **bijection**, think of maintaining mappings in **both directions**.
* One hash map checks consistency.
* Two hash maps ensure a valid one-to-one relationship.
