# Letter Combinations of a Phone Number

## Problem

Given a string containing digits from `2` to `9`, return all possible letter combinations based on the phone keypad mapping.

---

# Brute Force

## Idea

Try every possible letter for every digit and generate all valid strings.

### Complexity

- **Time:** O(4^N)
- **Space:** O(N)

---

# Optimal Approach (Backtracking)

## Key Observations

- Every digit maps to multiple letters.
- For each digit, choose exactly one letter.
- Build the answer one character at a time.

### Explanation

- Create a mapping from digits to their corresponding letters.
- Process one digit at a time.
- For the current digit, iterate through all its possible letters.
- Add one letter, recurse for the next digit, then backtrack.
- When all digits are processed, store the generated string.

---

## Algorithm

1. Handle the empty input case.
2. Create the digit-to-letter mapping.
3. Start recursion from the first digit.
4. Iterate through all letters of the current digit.
5. Choose one letter.
6. Recurse for the next digit.
7. Backtrack.
8. Store the string when all digits are processed.

---

## Complexity

- **Time:** `O(4^N)`
- **Space:** `O(N)`

---

# Code

```cpp
class Solution {
public:
    void solve(string &digits,string &curr, vector<string>&ans , unordered_map<char,string> &mp, int i,int count){
        if(count==digits.size()){
            ans.push_back(curr);
            return;
        }
        string letters=mp[digits[i]];
        for(char c:letters){
            curr.push_back(c);
            solve(digits,curr,ans,mp,i+1,count+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string curr="";
        unordered_map<char,string> mp = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        solve(digits,curr,ans,mp,0,0);
        return ans;
    }
};
```
---

# Interview Discussion

- Why backtracking?
  - Every digit has multiple choices, and we need to explore every combination.
- Why no Take / Don't Take?
  - We must choose exactly one letter for every digit.
- Why use a `for` loop?
  - To iterate through all possible letters mapped to the current digit.

---

# What I Learned ⭐

- This follows the **for-loop backtracking** pattern.
- Each recursion level processes one digit.
- Each branch represents choosing one letter for that digit.