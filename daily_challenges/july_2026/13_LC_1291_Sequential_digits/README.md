# LC 1291 - Sequential Digits

## Problem

An integer has **sequential digits** if every digit is exactly one greater than its previous digit.

Examples:

- `1234` ✅
- `4567` ✅
- `1357` ❌
- `1245` ❌

Given two integers `low` and `high`, return all sequential digit numbers in the range **[low, high]** in sorted order.

---

# Brute Force Approach

## Idea

Iterate through every number from `low` to `high`.

For every number:

- Check whether each adjacent digit differs by exactly `1`.
- If yes, add it to the answer.

### Algorithm

1. Traverse from `low` to `high`.
2. For every number:
   - Extract digits from right to left.
   - Verify that every previous digit is exactly one smaller than the current digit.
3. If valid, add it to the answer.

### Complexity

- **Time Complexity:** `O((high-low) × D)`
  - `D` = Number of digits (maximum 10)
- **Space Complexity:** `O(1)`

### Drawback

The range can be as large as

```
10
```

to

```
10^9
```

Checking every number is far too expensive.

---

# Observation

Instead of checking every integer...

Ask:

> **How many sequential numbers actually exist?**

Let's list them.

### 2 Digits

```
12
23
34
45
56
67
78
89
```

Total = **8**

---

### 3 Digits

```
123
234
345
456
567
678
789
```

Total = **7**

---

### 4 Digits

```
1234
2345
3456
4567
5678
6789
```

Total = **6**

Continuing similarly,

| Digits | Count |
|---------|------:|
|2|8|
|3|7|
|4|6|
|5|5|
|6|4|
|7|3|
|8|2|
|9|1|

Total sequential numbers:

```
8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 36
```

There are only **36 possible sequential numbers**.

So instead of searching through billions of integers,

**generate only these 36 numbers.**

---

# Optimal Approach (Sliding Window)

## Key Idea

Take the string

```
"123456789"
```

Every sequential number is simply a substring of this string.

For example,

Window Size = 2

```
12
23
34
45
56
67
78
89
```

Window Size = 3

```
123
234
345
456
567
678
789
```

Window Size = 4

```
1234
2345
3456
4567
5678
6789
```

Continue until window size = 9.

For every generated number:

- Convert it to an integer.
- If it lies in the range `[low, high]`, add it to the answer.

---

# Algorithm

1. Store

```cpp
string s = "123456789";
```

2. For every possible length from **2 to 9**
3. Move a sliding window across the string.
4. Extract the substring.
5. Convert it to an integer.
6. If it lies within `[low, high]`, store it.

---

# Code

```cpp
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        string s = "123456789";
        vector<int> ans;

        for (int len = 2; len <= 9; len++) {

            for (int left = 0; left + len <= 9; left++) {

                string num = s.substr(left, len);

                int value = stoi(num);

                if (value >= low && value <= high) {
                    ans.push_back(value);
                }
            }
        }

        return ans;
    }
};
```

---

# Complexity

There are only **36** sequential numbers.

Each substring has at most **9 digits**.

### Time Complexity

```
O(36 × 9)
≈ O(1)
```

### Space Complexity

```
O(1)
```

(excluding the output array)

---

# Interview Discussion

### Why is this optimal?

Instead of searching the entire range,

```
low → high
```

we generate only the **valid candidates**.

Search Space:

```
≈ 10^9 numbers
```

Valid Candidates:

```
36 numbers
```

Generating candidates is much faster than validating every number.

---

# What I Learned ⭐

- Don't always iterate through the entire search space.
- Sometimes the number of **valid candidates** is extremely small.
- Sliding Window is useful not only for arrays but also for generating fixed-length substrings.
- Converting a brute-force search into candidate generation is a common interview optimization technique.