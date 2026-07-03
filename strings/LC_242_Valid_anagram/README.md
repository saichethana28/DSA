# LC 242 - Valid Anagram

## Problem

Given two strings `s` and `t`, determine whether `t` is an anagram of `s`.

Two strings are anagrams if they contain the **same characters with the same frequencies**, regardless of their order.

---

## Approach 1 - Hash Map

### Thought Process

* If the lengths are different, they cannot be anagrams.
* Count the frequency of every character in `s`.
* Traverse `t` and decrease the corresponding frequency.
* If every frequency becomes zero, the strings are anagrams.

---

## Approach 2 - Frequency Array (Optimized)

### Key Observation 💡

The strings contain only **lowercase English letters**.

Instead of using a hash map, we can use a frequency array of size **26**.

* Increment frequencies while traversing `s`.
* Decrement frequencies while traversing `t`.
* If every frequency is zero, the strings are anagrams.

This avoids hashing and is slightly faster.

---

## Example

**Input**

```text
s = "anagram"
t = "nagaram"
```

Frequency after processing both strings:

```text
a : 0
b : 0
c : 0
...
z : 0
```

Since every frequency is zero, return:

```text
true
```

---

## Complexity

### Approach 1 (Hash Map)

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(k)`

where `k` is the number of distinct characters.

---

### Approach 2 (Frequency Array)

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

Since the array size is always **26**.

---

## Follow-up

If the strings contain **Unicode characters**, a fixed-size array is no longer sufficient.

In that case, use an `unordered_map<char, int>` (or an appropriate Unicode-aware map) to store character frequencies.

---

## What I Learned ⭐

* Frequency counting is one of the most common hashing techniques.
* If the character set is fixed (like lowercase English letters), an array is simpler and faster than a hash map.
* Always choose the data structure based on the constraints.
