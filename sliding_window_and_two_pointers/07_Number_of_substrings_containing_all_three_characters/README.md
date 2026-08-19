# Number of Substrings Containing All Three Characters

## Problem Statement

Given a string `s` containing only `a`, `b`, and `c`, return the number of substrings containing all three characters.

### Example

```text
Input: s = "abcabc"
Output: 10
```

## Brute Force

- Generate all substrings.
- Track whether `a`, `b`, and `c` are present.
- If all three are present, increment the count.

**Time:** `O(N²)`  
**Space:** `O(1)`

## Better Approach

- Generate substrings from every starting index.
- Once all three characters are present, all further extensions are also valid.
- Add `n - j` and break.

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            vector<int> freq(3, 0);

            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                if(freq[0] && freq[1] && freq[2]) {
                    count += n - j;
                    break;
                }
            }
        }

        return count;
    }
};
```

**Time:** `O(N²)`  
**Space:** `O(1)`

## Optimal Approach

- Store the **last seen index** of `a`, `b`, and `c`.
- For every index `i`, update the last occurrence.
- Find the minimum of the three last-seen indices.
- `min(lastSeen) + 1` gives the number of valid substrings ending at `i`.

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastseen(3, -1);
        int count = 0;

        for(int i = 0; i < s.size(); i++) {
            lastseen[s[i] - 'a'] = i;

            if(lastseen[0] != -1 &&
               lastseen[1] != -1 &&
               lastseen[2] != -1) {

                count += 1 + min({
                    lastseen[0],
                    lastseen[1],
                    lastseen[2]
                });
            }
        }

        return count;
    }
};
```

**Time:** `O(N)`  
**Space:** `O(1)`

## Key Takeaway

> Store the **last seen index** of `a`, `b`, and `c`.

> `min(lastSeen) + 1` = number of valid substrings ending at the current index.