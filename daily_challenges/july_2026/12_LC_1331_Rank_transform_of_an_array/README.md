# LC 1331 - Rank Transform of an Array

## Problem

Given an integer array `arr`, replace every element with its **rank**.

Rules:

- Rank starts from **1**.
- Equal elements receive the **same rank**.
- Larger elements have larger ranks.
- Ranks should be as small as possible.

---

## Brute Force Approach

For every element:

1. Count how many distinct elements are smaller than it.
2. Rank = Count + 1.

### Complexity

- Time Complexity: **O(N²)**
- Space Complexity: **O(1)**

This approach is inefficient for large arrays.

---

## Better Approach (Sorting + Binary Search)

### Idea

Instead of comparing every element with every other element:

1. Copy the original array.
2. Sort the copied array.
3. Remove duplicate elements.
4. For every element in the original array:
   - Find its position in the sorted unique array using **Binary Search (`lower_bound`)**.
   - Rank = Index + 1.

### Example

Input

```
arr = [40,10,20,30]
```

Sorted copy

```
10 20 30 40
```

Ranks

```
10 -> 1
20 -> 2
30 -> 3
40 -> 4
```

Output

```
[4,1,2,3]
```

### Complexity

- Sorting: **O(N log N)**
- Binary Search for each element: **O(log N)**
- Total: **O(N log N)**
- Space: **O(N)**

---

## Optimal Approach (Sorting + Hash Map)

### Observation

In the previous approach, we perform a binary search for every element.

Instead, after sorting the unique elements, we can directly assign ranks using a hash map.

Example

```
Sorted Unique

10 20 30 40

↓

Hash Map

10 -> 1
20 -> 2
30 -> 3
40 -> 4
```

Now each lookup becomes **O(1)** on average.

### Algorithm

1. Copy the array.
2. Sort the copy.
3. Remove duplicates.
4. Store every value with its rank in an `unordered_map`.
5. Traverse the original array and replace every element with its mapped rank.

### Complexity

- Sorting: **O(N log N)**
- Build Hash Map: **O(N)**
- Lookup: **O(N)**

Overall

- **Time Complexity:** **O(N log N)**
- **Space Complexity:** **O(N)**

---

## Interview Discussion

### Which approach would I use?

I would first explain the **Sorting + Binary Search** solution because it is simple and easy to derive.

If the interviewer asks whether the lookup step can be optimized, I would suggest replacing the repeated binary searches with an **unordered_map**.

Although both approaches have the same asymptotic complexity (`O(N log N)`), the hash map removes repeated binary searches.

In practice, the binary search solution may sometimes run faster because `lower_bound` on a vector has excellent cache locality and very small constant factors.

---

## What I Learned ⭐

- `sort()` followed by `unique()` is a common technique to obtain distinct sorted values.
- `lower_bound()` can efficiently determine the rank of an element in a sorted array.
- A Hash Map can replace repeated binary searches when multiple lookups are required.
- Better asymptotic lookup complexity does not always guarantee faster runtime because of constant factors.