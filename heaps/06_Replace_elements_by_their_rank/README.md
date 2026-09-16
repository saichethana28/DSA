# Replace Elements by Their Rank

## Problem Statement

Given an array, replace every element with its rank.

- Smallest element gets rank `0`.
- The next smallest gets rank `1`.
- Repeating elements get different ranks based on their original positions.
- Modify the array in-place.

### Examples

**Input:**
```text
arr = [10, 40, 20]
```

**Output:**
```text
[0, 2, 1]
```

**Input:**
```text
arr = [1, 5, 3, 4, 3]
```

**Output:**
```text
[0, 4, 1, 3, 2]
```

## Observations

- We need to preserve the original positions of elements.
- For every element, its position in sorted order becomes its rank.
- For duplicate values, the element with the smaller original index gets the smaller rank.
- We can store `(value, originalIndex)` to remember where each element came from.
- Since `arr[i] <= 10^6`, we can also use a frequency/counting approach.

## Brute Force

- For every element, count how many elements are smaller than it.
- For equal elements, count the equal elements appearing before it.
- The resulting count gives the rank.
- Repeat this for every element.

```cpp
class Solution {
public:
    void replaceWithRank(vector<int>& arr) {
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            int rank = 0;

            for(int j = 0; j < n; j++) {
                if(arr[j] < arr[i]) {
                    rank++;
                }
                else if(arr[j] == arr[i] && j < i) {
                    rank++;
                }
            }

            arr[i] = rank;
        }
    }
};
```

### Complexity

- **Time:** `O(N × N)` — for every element, scan all `N` elements to find its rank → **O(N²)**
- **Space:** `O(1)` — no extra data structure is used.

## Optimal Approach 1 — Sorting with Original Index

- Store every element as `(value, originalIndex)`.
- Sort pairs by value, and for equal values by original index.
- The position in the sorted vector is the rank.
- Use the stored original index to put the rank back into the original array.

```cpp
class Solution {
public:
    static bool compare(pair<int,int> p1, pair<int,int> p2) {
        if(p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return p1.first < p2.first;
    }

    void replaceWithRank(vector<int>& arr) {
        vector<pair<int,int>> v;

        for(int i = 0; i < arr.size(); i++) {
            v.push_back({arr[i], i});
        }

        sort(v.begin(), v.end(), compare);

        int rank = 0;

        for(int i = 0; i < v.size(); i++) {
            arr[v[i].second] = rank;
            rank++;
        }
    }
};
```

### Complexity

- **Time:** `O(N) + O(N log N) + O(N)` — create pairs, sort them, and assign ranks → **O(N log N)**
- **Space:** `O(N)` — store `N` `(value, index)` pairs.

## Optimal Approach 2 — Frequency Array

- Since every value is between `1` and `10^6`, maintain the frequency of every value.
- Scan values from smallest to largest to determine how many elements come before each value.
- Store the starting rank of every value.
- Traverse the original array and assign the next available rank for that value.
- For duplicates, increment its rank so earlier occurrences get smaller ranks.

```cpp
class Solution {
public:
    void replaceWithRank(vector<int>& arr) {
        const int MAXV = 1000000;

        vector<int> freq(MAXV + 1, 0);
        vector<int> rank(MAXV + 1, 0);

        for(int x : arr) {
            freq[x]++;
        }

        int currRank = 0;

        for(int value = 1; value <= MAXV; value++) {
            if(freq[value] > 0) {
                rank[value] = currRank;
                currRank += freq[value];
            }
        }

        vector<int> nextRank = rank;

        for(int i = 0; i < arr.size(); i++) {
            int value = arr[i];
            arr[i] = nextRank[value];
            nextRank[value]++;
        }
    }
};
```

### Complexity

- **Time:** `O(N) + O(10^6) + O(N)` — build frequencies, scan the value range, and assign ranks → **O(N + 10^6)**
- **Space:** `O(10^6)` — frequency, rank, and next-rank arrays.

## Key Takeaways

- **Need original positions after sorting → store `(value, index)`.**
- **Sorted position = rank**, and `pair.second` tells where to place it.
- **Duplicate values → process earlier original indices first.**
- If the value range is small and bounded, a **frequency/counting approach** can avoid sorting.
- General solution: **O(N log N)** time; constraint-specific counting solution: **O(N + 10^6)** time.