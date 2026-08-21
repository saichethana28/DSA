# Subarrays with K Different Integers

## Problem Statement

Given an integer array `nums` and an integer `k`, return the number of subarrays containing exactly `k` distinct integers.

## Brute Force

- Generate all subarrays.
- Maintain a frequency map.
- Count distinct elements.
- If distinct elements become `k`, increment the answer.
- If distinct elements become greater than `k`, break.

**Time:** `O(N²)`  
**Space:** `O(N)`

## Optimal Approach

Use the **At Most** technique:

```text
Exactly K = At Most K - At Most (K - 1)
```

- `atmost(nums, k)` counts subarrays having at most `k` distinct elements.
- Use a sliding window with a frequency map.
- If distinct elements become greater than `k`, shrink the window.
- `r - l + 1` gives the number of valid subarrays ending at `r`.

```cpp
class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        if(k < 0)
            return 0;

        int l = 0, r = 0;
        int count = 0;
        unordered_map<int, int> mp;

        while(r < nums.size()) {
            mp[nums[r]]++;

            while(mp.size() > k) {
                mp[nums[l]]--;

                if(mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }

                l++;
            }

            count += r - l + 1;
            r++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};
```

**Time:** `O(N)`  
**Space:** `O(N)`

## Key Takeaway

> **Exactly K distinct = At Most K − At Most (K - 1)**

> `r - l + 1` counts all valid subarrays ending at `r`.