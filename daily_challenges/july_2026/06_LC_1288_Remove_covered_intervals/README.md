# LC 1288 - Remove Covered Intervals

## Problem

Given a list of intervals, remove all intervals that are completely covered by another interval.

An interval `[a, b]` is covered by `[c, d]` if:

```text
c <= a
and
b <= d
```

Return the number of remaining intervals.

---

## My Initial Thought (Brute Force)

For every interval, compare it with every other interval.

If another interval satisfies:

```text
other.start <= current.start
and
current.end <= other.end
```

then the current interval is covered and can be removed.

### Complexity

* **Time Complexity:** `O(n²)`
* **Space Complexity:** `O(1)`

---

## Key Observation 💡

Instead of comparing every interval with every other interval, we can sort the intervals.

### Sorting Rule

* Sort by **starting point in ascending order**.
* If two intervals have the **same starting point**, sort by **ending point in descending order**.

Example:

```text
[1,5]
[1,4]
```

instead of

```text
[1,4]
[1,5]
```

This ensures that the larger interval appears first and can correctly cover the smaller one.

---

## Greedy Approach

After sorting:

* Maintain the maximum ending point seen so far (`maxEnd`).
* Traverse the intervals from left to right.

For every interval:

* If its ending point is **less than or equal to `maxEnd`**, it is covered.
* Otherwise, update `maxEnd`.

Finally,

```text
Remaining Intervals = Total Intervals - Covered Intervals
```

---

## Example

**Input**

```text
[[1,4],[3,6],[2,8]]
```

After Sorting

```text
[[1,4],[2,8],[3,6]]
```

Traversal

```text
maxEnd = 4

[2,8]
maxEnd = 8

[3,6]
6 <= 8
Covered
```

Remaining intervals:

```text
2
```

---

## Complexity

* **Time Complexity:** `O(n log n)` (sorting dominates)
* **Space Complexity:** `O(1)` (excluding the sorting algorithm)

---

## What I Learned ⭐

* Many interval problems become easier after sorting.
* Choosing the correct sorting order is often the key observation.
* When two intervals have the same starting point, sorting by the ending point in descending order prevents missing covered intervals.
* A greedy scan after sorting can replace an `O(n²)` comparison approach.
