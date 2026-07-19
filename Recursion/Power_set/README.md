# Power Set (Print All Possible Subsequences of a String)

## Problem

Given a string `s`, print all possible subsequences of the string.

### Example

**Input:**
```text
s = "abc"
```

**Output:**
```text
["", "a", "ab", "abc", "ac", "b", "bc", "c"]
```

> **Note:** Some platforms (like GeeksforGeeks) include the empty subsequence `""`, while others may ask for only non-empty subsequences.

---

# Brute Force Approach

## Idea

Generate every possible combination of characters using bit manipulation.

Each bit represents whether a character is included (`1`) or excluded (`0`) in the current subsequence.

For a string of length `n`, there are `2ⁿ` possible bitmasks.

---

## Algorithm

1. Iterate through all numbers from `0` to `(1<<n)-1`.
2. For every bitmask:
   - Check each bit.
   - If the bit is set, include that character.
3. Store the generated subsequence.

---

## Complexity Analysis

- **Time Complexity:** **O(n × 2ⁿ)**
- **Space Complexity:** **O(n)** (excluding output)

---

## Code

```cpp
class Solution {
public:
    vector<string> powerSet(string s) {
        vector<string> ans;
        int n = s.size();

        for (int mask = 0; mask < (1 << n); mask++) {
            string curr = "";

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    curr.push_back(s[i]);
            }

            ans.push_back(curr);
        }

        return ans;
    }
};
```

---

# Optimal Approach (Recursion / Backtracking)

## Key Observation

For every character, we have only two choices:

- Include it in the current subsequence.
- Exclude it from the current subsequence.

By recursively making these two choices for every character, we can generate all possible subsequences.

---

## Algorithm

1. Start from index `0` with an empty string.
2. For every character:
   - Include it and recurse.
   - Backtrack.
   - Exclude it and recurse.
3. When all characters are processed (`i == s.size()`), store the current subsequence.

---

## Complexity Analysis

- **Time Complexity:** **O(n × 2ⁿ)**
- **Space Complexity:** **O(n)** (excluding output)

---

## Code

```cpp
class Solution {
public:
    void solve(string &curr, string &s, int i, vector<string> &ans) {
        if (i == s.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(s[i]);
        solve(curr, s, i + 1, ans);

        curr.pop_back();
        solve(curr, s, i + 1, ans);
    }

    vector<string> powerSet(string s) {
        vector<string> ans;
        string curr = "";

        solve(curr, s, 0, ans);

        return ans;
    }
};
```

---

# Interview Discussion

- Every character has two choices: **Take** or **Don't Take**.
- Backtracking restores the previous state after exploring the **Take** branch.
- The recursion stops only after decisions for all characters have been made.
- The empty subsequence is included only if the problem statement requires it.

---

# What I Learned ⭐

- Learned the classic **Take / Don't Take** recursion pattern.
- Understood that recursion explores decisions for every character before storing a subsequence.
- Strengthened my understanding of backtracking using `push_back()` and `pop_back()`.
- Learned that a power set contains exactly **2ⁿ** subsequences.
- Learned an alternative brute-force solution using **bitmasking**.