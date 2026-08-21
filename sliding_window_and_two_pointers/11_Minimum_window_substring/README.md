# Minimum Window Substring

## Problem Statement

Given strings `s` and `t`, find the minimum window substring of `s` that contains all characters of `t` including duplicates.

If no such substring exists, return `""`.

## Brute Force

- Generate all substrings.
- Maintain the frequency of characters in the current substring.
- Check whether it contains all characters of `t`.
- Keep the minimum valid window.

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int minlen = n + 1;
        int start = -1;

        for(int i = 0; i < n; i++) {
            vector<int> freq(256, 0);

            for(char c : t) {
                freq[c]++;
            }

            for(int j = i; j < n; j++) {
                freq[s[j]]--;

                bool valid = true;

                for(int k = 0; k < 256; k++) {
                    if(freq[k] > 0) {
                        valid = false;
                        break;
                    }
                }

                if(valid) {
                    if(j - i + 1 < minlen) {
                        minlen = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        if(start == -1)
            return "";

        return s.substr(start, minlen);
    }
};
```

**Time:** `O(N² × 256)` → `O(N²)`  
**Space:** `O(256)` → `O(1)`

## Optimal Approach

- Use **Sliding Window + Frequency Array**.
- Store the required frequency of characters of `t`.
- Expand `r` until the window contains all required characters.
- Once valid, shrink from `l` as much as possible.
- Store the minimum valid window.

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256, 0);

        int n = s.size();
        int l = 0, r = 0;
        int minlen = n + 1;
        int count = 0;
        int start = -1;

        for(char c : t) {
            freq[c]++;
        }

        while(r < n) {
            if(freq[s[r]] > 0) {
                count++;
            }

            freq[s[r]]--;

            while(count == t.size()) {
                if(r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    start = l;
                }

                freq[s[l]]++;

                if(freq[s[l]] > 0) {
                    count--;
                }

                l++;
            }

            r++;
        }

        if(start == -1)
            return "";

        return s.substr(start, minlen);
    }
};
```

**Time:** `O(N + M)`  
**Space:** `O(256)` → `O(1)`

## Key Takeaway

> **Expand `r` until the window is valid → shrink `l` as much as possible → store the minimum window.**