# Generate Binary Strings Without Adjacent Zeros

**LeetCode 3211 - Medium**

## Problem

Given an integer `n`, generate all binary strings of length `n` such that **no two consecutive characters are '0'**.

Return the valid strings in any order.

---

# Brute Force Approach

## Idea

Generate all possible binary strings of length `n` and check whether each string contains consecutive `'0'`s.

If a string is valid, add it to the answer.

### Algorithm

1. Generate all binary strings of length `n`.
2. Check every generated string for adjacent `'0'`s.
3. If no consecutive `'0'`s are found, add it to the answer.

### Complexity

- **Time Complexity:** `O(2^N × N)`
- **Space Complexity:** `O(N)` (Recursion Stack)

### Code

```cpp
// Generate all binary strings and validate each one.
// Not the optimal approach.
```

---

# Optimal Approach (Backtracking)

## Key Observation

- Instead of generating all strings and checking validity, generate **only valid strings**.
- A `'1'` can always be appended.
- A `'0'` can be appended only if:
  - The current string is empty, or
  - The previous character is `'1'`.
- This prunes invalid branches of the recursion tree.

### Algorithm

1. If the current string length becomes `n`, add it to the answer.
2. If the current string is empty or ends with `'1'`:
   - Append `'0'`.
   - Recurse.
   - Backtrack.
3. Append `'1'`.
4. Recurse.
5. Backtrack.

### Complexity

- **Time Complexity:** `O(F(N) × N)`, where `F(N)` is the number of valid strings (Fibonacci-like growth).
- **Space Complexity:** `O(N)` (Recursion Stack)

### Code

```cpp
class Solution {
public:
    void solve(string &curr, vector<string> &ans, int n) {
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }

        if (curr.empty() || curr.back() == '1') {
            curr.push_back('0');
            solve(curr, ans, n);
            curr.pop_back();
        }

        curr.push_back('1');
        solve(curr, ans, n);
        curr.pop_back();
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        string curr = "";

        solve(curr, ans, n);

        return ans;
    }
};
```

---

# Interview Discussion

- This is a classic **Backtracking** problem.
- Instead of generating all binary strings, invalid branches are **pruned** during recursion.
- The recursion follows the pattern:
  - **Choose → Explore → Undo (Backtrack)**.
- Passing the current string by reference avoids unnecessary string copying.

---

# What I Learned ⭐

- Backtracking generates only valid solutions instead of filtering invalid ones.
- Pruning recursion early significantly reduces unnecessary work.
- The previous character is sufficient to decide whether `'0'` can be appended.
- `push_back()` and `pop_back()` efficiently implement the backtracking pattern.
- Similar problems can often be solved by changing only the validity condition while keeping the recursion template unchanged.