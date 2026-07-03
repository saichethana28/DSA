# LC 451 - Sort Characters By Frequency

## Problem

Given a string `s`, sort its characters in **decreasing order of their frequency**.

The frequency of a character is the number of times it appears in the string. If multiple characters have the same frequency, any valid ordering is accepted.

---

## Approach 1 - Frequency Array

### Thought Process

Since the string contains only:

* Digits (`0-9`)
* Uppercase letters (`A-Z`)
* Lowercase letters (`a-z`)

we can maintain a frequency array indexed using the ASCII value offset.

### Steps

1. Count the frequency of every character.
2. Store both the frequency and the corresponding character index.
3. Sort the array in descending order of frequency.
4. Append each character `frequency` times to the answer.

### Complexity

* **Time Complexity:** `O(n + k log k)`
* **Space Complexity:** `O(k)`

where `k` is the size of the character set used.

---

## Approach 2 - Hash Map (Cleaner)

### Key Observation 💡

Instead of maintaining a fixed-size frequency array, we can use a hash map to count frequencies.

### Steps

1. Count frequencies using an `unordered_map`.
2. Store all `(character, frequency)` pairs into a vector.
3. Sort the vector based on frequency.
4. Construct the answer by repeating each character according to its frequency.

This approach is more generic and works even if the character set changes.

---

## Example

**Input**

```text
s = "tree"
```

Frequency Count

```text
e → 2
t → 1
r → 1
```

After Sorting

```text
e → 2
t → 1
r → 1
```

Output

```text
"eert"
```

(`"eetr"` is also valid.)

---

## Complexity

### Approach 1

* **Time Complexity:** `O(n + k log k)`
* **Space Complexity:** `O(k)`

### Approach 2

* **Time Complexity:** `O(n + k log k)`
* **Space Complexity:** `O(k)`

---

## What I Learned ⭐

* Frequency counting is one of the most common applications of hashing.
* A frequency array works well when the character set is fixed and known.
* A hash map is cleaner, more flexible, and easier to adapt for different character sets.
* `string(freq, ch)` is a neat STL constructor for appending the same character multiple times.
* Custom comparators allow sorting by frequency instead of character values.
