# Longest Substring with At Most K Distinct Characters

## Problem Statement

Given a string `str` and an integer `k`, find the length of the longest substring containing at most `k` distinct characters.

## Brute Force

- Generate all substrings.
- Maintain the frequency of characters.
- If the number of distinct characters is `<= k`, update the maximum length.

**Time:** `O(N²)`  
**Space:** `O(N)`

## Better Approach

- Use **Sliding Window + HashMap**.
- Expand the window using `r`.
- Store the frequency of each character.
- If distinct characters become greater than `k`, shrink using `while` until the window becomes valid.
- Update the maximum length.

```cpp
int kDistinctChars(int k, string &str)
{
    unordered_map<char, int> mp;

    int l = 0, r = 0;
    int maxlen = 0;

    while(r < str.size()) {
        mp[str[r]]++;

        while(mp.size() > k) {
            mp[str[l]]--;

            if(mp[str[l]] == 0) {
                mp.erase(str[l]);
            }

            l++;
        }

        maxlen = max(maxlen, r - l + 1);
        r++;
    }

    return maxlen;
}
```

**Time:** `O(N)`  
**Space:** `O(N)`

## Optimal Approach

- Since we only need the **maximum length**, we don't need to shrink the window until it becomes fully valid.
- If distinct characters become greater than `k`, shrink **only once** using `if`.
- Continue expanding `r`.

```cpp
int kDistinctChars(int k, string &str)
{
    unordered_map<char, int> mp;

    int l = 0, r = 0;
    int maxlen = 0;

    while(r < str.size()) {
        mp[str[r]]++;

        if(mp.size() > k) {
            mp[str[l]]--;

            if(mp[str[l]] == 0) {
                mp.erase(str[l]);
            }

            l++;
        }

        maxlen = max(maxlen, r - l + 1);
        r++;
    }

    return maxlen;
}
```

**Time:** `O(N)`  
**Space:** `O(N)`

## Key Takeaway

> **Better:** `while` → make the window fully valid.  
> **Optimal:** `if` → shrink only once because we only care about the maximum length.