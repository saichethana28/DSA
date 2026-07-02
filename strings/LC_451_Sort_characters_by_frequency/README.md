# LC 451 - Sort Characters By Frequency

## Problem

Given a string `s`, sort its characters in **decreasing order of their frequency** and return the resulting string.

If multiple characters have the same frequency, any valid order is accepted.

---

## Key Observation 💡

The problem does **not** ask us to sort the entire string directly.

Instead:

1. Count how many times each character appears.
2. Sort the characters based on their frequencies.
3. Construct the answer by repeating each character according to its frequency.

---

## Approach

### Step 1

Traverse the string and count the frequency of every character using a hash map.

### Step 2

Store all `(character, frequency)` pairs into a vector.

### Step 3

Sort the vector in **descending order of frequency**.

### Step 4

Traverse the sorted vector and append each character `frequency` times to the answer string.

---

## Example

**Input**

```text
s = "tree"
```

Frequency Map

```text
t → 1
r → 1
e → 2
```

After Sorting

```text
e → 2
t → 1
r → 1
```

Output

```text
"eetr"
```

(or `"eert"`)

---

## Complexity

* **Time Complexity:** `O(n + k log k)`

  * `n` = length of the string
  * `k` = number of distinct characters

* **Space Complexity:** `O(k)`

---

## What I Learned ⭐

* Hash maps are useful for frequency counting.
* After counting frequencies, converting the hash map into a vector makes sorting easy.
* A custom comparator can sort based on frequency instead of characters.
* Building the answer using `string(freq, ch)` is cleaner than appending characters one by one.
