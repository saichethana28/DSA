# Word Break

## Problem

Given a string `s` and a dictionary of strings `wordDict`, determine whether the string can be segmented into a space-separated sequence of one or more dictionary words.

- A word from the dictionary can be reused multiple times.
- Return `true` if such a segmentation is possible, otherwise return `false`.

**Example**

```text
Input:
s = "leetcode"
wordDict = ["leet", "code"]

Output:
true

Explanation:
"leetcode" can be segmented as "leet code".
```

---

# Optimal Approach (Memoization)

## Key Observations

- At any position in the string, we need to determine whether the remaining suffix can be segmented into valid dictionary words.
- The recursion state depends only on the current starting index.
- Multiple recursion paths may reach the same index, leading to overlapping subproblems.
- Memoization ensures that each state is computed only once.
- Using an `unordered_set` provides average **O(1)** dictionary lookup.

## Approach

- Store all dictionary words in an `unordered_set` for fast lookup.
- Define `solve(i)` to check whether the substring starting from index `i` can be segmented.
- If `i` reaches the end of the string, return `true`.
- If the answer for index `i` is already computed, return it from the DP array.
- Build the current word character by character starting from index `i`.
- Whenever the current word exists in the dictionary, recursively check the remaining suffix.
- If any recursive call returns `true`, store the result and return `true`.
- If no valid segmentation exists, store `false` and return it.

## Code

```cpp
class Solution {
public:
    bool solve(string &s, unordered_set<string>& st, vector<int>& dp, int i) {
        if (i == s.size()) {
            return true;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        string curr = "";

        for (int j = i; j < s.size(); j++) {
            curr += s[j];

            if (st.count(curr)) {
                if (solve(s, st, dp, j + 1)) {
                    dp[i] = 1;
                    return true;
                }
            }
        }

        dp[i] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        vector<int> dp(s.size() + 1, -1);

        for (string &word : wordDict) {
            st.insert(word);
        }

        return solve(s, st, dp, 0);
    }
};
```

### Complexity Analysis

**Time Complexity:** **O(N²)**

**Reasoning:**
- There are **O(N)** unique DP states (one for each starting index).
- For each state, we extend the current substring up to **O(N)** characters.
- Dictionary lookup using `unordered_set` takes **O(1)** on average.

**Space Complexity:** **O(N)**

**Reasoning:**
- `O(N)` for the DP array.
- `O(N)` recursion stack in the worst case.
- `unordered_set` stores the dictionary words.

---

# Interview Notes

- The recursion state is:
  > **Can the suffix starting from index `i` be segmented into dictionary words?**
- This is a classic **Recursion + Memoization** problem with overlapping subproblems.
- Memoization avoids recomputing the same starting index multiple times.
- Building the substring incrementally (`curr += s[j]`) is more efficient than repeatedly calling `substr()`.
- An `unordered_set` is preferred over an `unordered_map` since only membership checking is required.

---

# What I Learned ⭐

- How to define DP states based on the current index of a string.
- How memoization converts an exponential recursive solution into a polynomial-time solution.
- How overlapping subproblems arise naturally in recursive string segmentation.
- Why `unordered_set` is a better choice than `unordered_map` when only lookups are needed.
- How incrementally building a substring avoids the overhead of repeated `substr()` calls.