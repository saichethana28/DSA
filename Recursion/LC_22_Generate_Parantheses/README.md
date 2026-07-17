# Generate Parentheses

## Problem

Given `n` pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

### Example

**Input:**
```text
n = 3
```

**Output:**
```text
["((()))","(()())","(())()","()(())","()()()"]
```

---

# Brute Force Approach

## Idea

Generate every possible string of length `2n` consisting of `'('` and `')'`.

For each generated string, check whether it is a valid parentheses sequence using a balance counter.

A string is valid if:

- Balance never becomes negative.
- Final balance is equal to zero.

Since most generated strings are invalid, this approach performs a lot of unnecessary work.

---

## Algorithm

1. Generate every possible string of length `2n`.
2. For every generated string:
   - Traverse it.
   - Increase balance for `'('`.
   - Decrease balance for `')'`.
   - If balance becomes negative, it is invalid.
3. If final balance is zero, store the string.

---

## Complexity Analysis

- **Time Complexity:** **O(2^(2n) × n)**
- **Space Complexity:** **O(2n)** (excluding output)

---

## Code

```cpp
class Solution {
public:
    bool isValid(string &s) {
        int balance = 0;

        for (char ch : s) {
            if (ch == '(')
                balance++;
            else
                balance--;

            if (balance < 0)
                return false;
        }

        return balance == 0;
    }

    void generate(string &curr, vector<string> &ans, int len) {
        if (curr.size() == len) {
            if (isValid(curr))
                ans.push_back(curr);
            return;
        }

        curr.push_back('(');
        generate(curr, ans, len);
        curr.pop_back();

        curr.push_back(')');
        generate(curr, ans, len);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;

        generate(curr, ans, 2 * n);

        return ans;
    }
};
```

---

# Optimal Approach (Backtracking)

## Key Observation

Instead of generating every possible string and checking validity later, we can ensure that every recursive call always represents a valid partial parentheses string.

At every step:

- We can place `'('` only if `open < n`.
- We can place `')'` only if `close < open`.

This prunes all invalid branches early.

---

## Algorithm

1. Start with an empty string.
2. Maintain:
   - `open` → Number of `'('` used.
   - `close` → Number of `')'` used.
3. If both become `n`, store the string.
4. If `open < n`, add `'('`, recurse, and backtrack.
5. If `close < open`, add `')'`, recurse, and backtrack.

---

## Complexity Analysis

- **Time Complexity:** **O(Cₙ × n)**

  where **Cₙ** is the **nth Catalan Number**.

  There are exactly **Cₙ** valid parentheses strings, each of length `2n`.

- **Space Complexity:** **O(n)** (excluding output)

---

## Code

```cpp
class Solution {
public:
    void solve(string &curr, vector<string> &ans, int open, int close, int n) {
        if (open == n && close == n) {
            ans.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            solve(curr, ans, open + 1, close, n);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            solve(curr, ans, open, close + 1, n);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;

        solve(curr, ans, 0, 0, n);

        return ans;
    }
};
```

---

# Interview Discussion

### Why is the brute-force approach inefficient?

It generates **all `2^(2n)` possible strings**, even though only a small fraction are valid parentheses sequences.

---

### Why is the backtracking approach better?

Backtracking generates **only valid partial strings**.

It prunes invalid branches immediately instead of generating and validating them later.

---

### Why are `open` and `close` passed by value?

Each recursive call maintains its own count of opening and closing brackets.

Since integers are copied for every recursive call, no explicit backtracking is required.

---

### Why is `curr` passed by reference?

Passing the string by reference avoids creating a new string at every recursive call.

The current state is restored using the standard backtracking pattern:

```cpp
curr.push_back(...);
solve(...);
curr.pop_back();
```

---

# What I Learned ⭐

- Learned the difference between **generate-all-and-check** and **generate-only-valid** approaches.
- Understood how backtracking prunes invalid states early.
- Strengthened my understanding of recursion state using `open` and `close`.
- Learned the importance of restoring state using `push_back()` and `pop_back()`.
- Learned that the number of valid parentheses strings follows the **Catalan Number** sequence.