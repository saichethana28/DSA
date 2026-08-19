# Longest Repeating Character Replacement

## Problem Statement

Given a string `s` containing uppercase English letters and an integer `k`, you can replace at most `k` characters. Return the length of the longest substring containing the same letter after performing the replacements.

## Brute Force

- Generate all substrings.
- Maintain character frequencies.
- `conversions = window length - maxFreq`
- If `conversions <= k`, update the answer.
- Break when the window becomes invalid.

**Time:** `O(N²)`  
**Space:** `O(1)`

## Better Approach

- Use **Sliding Window + Frequency Array**.
- Expand using `r`.
- `maxFreq` stores the highest frequency in the current window.
- If replacements needed `> k`, shrink using `while`.
- Recalculate `maxFreq` after shrinking.

**Time:** `O(26N)` → `O(N)`  
**Space:** `O(1)`

## Optimal Approach

- Same sliding window.
- Do **not** recalculate `maxFreq` when shrinking.
- If the window becomes invalid, shrink only once using `if`.
- We only need the **maximum length**, so keeping the previous `maxFreq` is sufficient.

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxlen = 0;
        int n = s.size();

        vector<int> freq(26, 0);
        int maxFreq = 0;

        while(r < n) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            if((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};
```

**Time:** `O(N)`  
**Space:** `O(1)`

## Key Takeaway

`window length - maxFreq` = number of replacements needed.

**Better:** shrink with `while` + recalculate `maxFreq`.

**Optimal:** shrink once with `if` + don't recalculate `maxFreq`.