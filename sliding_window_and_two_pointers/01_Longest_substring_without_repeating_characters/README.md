# Longest Substring Without Repeating Characters

## Problem Statement

Given a string `s`, find the length of the longest substring without repeating characters.

### Example

```text
Input: s = "abcabcbb"
Output: 3

Explanation:
The longest substring without repeating characters is "abc".
```

## Approach

- Use the **Sliding Window + Hashing** technique.
- Maintain a window `[l...r]` containing unique characters.
- Store the **last index** of every character.
- Expand the window using `r`.
- If the current character was seen before **inside the current window**, move `l` to one position after its previous occurrence.
- Update the maximum length after every valid window.

## Code

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);

        int maxlen = 0;
        int l = 0, r = 0;
        int n = s.size();

        while (r < n) {
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }

            int len = r - l + 1;
            maxlen = max(maxlen, len);

            hash[s[r]] = r;
            r++;
        }

        return maxlen;
    }
};
```

## Complexity

- **Time:** `O(N)`
- **Space:** `O(1)` — fixed-size hash array of 256 characters.

## Key Takeaways

- **Sliding Window:** `l` and `r` maintain the current substring.
- Store the **last occurrence index** of each character.
- On duplicate, move `l` to `lastIndex + 1`, but only if that index is inside the current window.
- **Never move `l` backwards.**