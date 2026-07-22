# Palindrome Partitioning

## Problem

Given a string `s`, partition it such that every substring of the partition is a palindrome.

Return **all possible palindrome partitionings**.

---

# Brute Force

## Idea

Generate every possible partition of the string and check whether every substring in the partition is a palindrome.

### Complexity

- **Time:** Exponential
- **Space:** O(N)

---

# Optimal Approach (Backtracking)

## Key Observations

- Every recursive call starts from a fixed index (`start`).
- From that index, try **every possible substring**.
- Only continue the recursion if the chosen substring is a palindrome.
- Once a palindrome substring is chosen, the next partition starts immediately after it (`end + 1`).

### Explanation

- Start from index `0`.
- Generate all substrings beginning at the current index.
- Check whether the current substring is a palindrome.
- If it is:
  - Add it to the current partition.
  - Recurse for the remaining string.
  - Backtrack by removing the last substring.
- When the entire string has been partitioned (`start == s.size()`), store the current partition.

---

## Algorithm

1. Start recursion from index `0`.
2. Generate every substring starting from the current index.
3. Check whether the substring is a palindrome.
4. If it is:
   - Add it to the current partition.
   - Recurse from the next index (`end + 1`).
   - Backtrack.
5. Store the partition when the complete string has been processed.

---

## Complexity

- **Time:** `O(N × 2^N)`
- **Space:** `O(N)`

---

# Code

```cpp
class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(string &s, vector<vector<string>> &ans,
               vector<string> &curr, int start) {

        if (start == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int j = start; j < s.size(); j++) {

            if (isPalindrome(s, start, j)) {

                curr.push_back(s.substr(start, j - start + 1));

                solve(s, ans, curr, j + 1);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> curr;

        solve(s, ans, curr, 0);

        return ans;
    }
};
```

---

# Interview Discussion

- Why use a `for` loop?
  - Every recursive call must try all possible substrings starting from the current index.

- Why recurse with `end + 1`?
  - The current substring has already been partitioned, so the next partition starts immediately after it.

- Why backtrack?
  - To remove the current substring and explore other possible partitions.

- Can this be optimized?
  - Yes. Precompute palindrome information using Dynamic Programming (DP) or memoization to avoid checking the same substrings repeatedly.

---

# What I Learned ⭐

- This problem follows the **for-loop backtracking** template.
- Each recursion level represents choosing the **next palindrome substring**.
- Instead of iterating over array elements or numbers, we iterate over **all substrings starting from the current index**.
- The recursion moves to `end + 1` because the chosen substring is already fixed.
- Palindrome checking can be further optimized using **DP/Memoization** without changing the backtracking logic.