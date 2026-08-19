# Count Number of Nice Subarrays

## Problem Statement

Given an array `nums` and an integer `k`, return the number of subarrays containing exactly `k` odd numbers.

### Example

```text
Input: nums = [1,1,2,1,1], k = 3
Output: 2
```

## Brute Force

- Generate all subarrays.
- Count the number of odd numbers.
- If odd count becomes `k`, increment the answer.
- If odd count exceeds `k`, break.

**Time:** `O(N²)`  
**Space:** `O(1)`

## Better Approach

- Convert the problem into a **Prefix Sum + HashMap** problem.
- Treat every odd number as `1` and every even number as `0`.
- Store the frequency of prefix sums.
- For current `sum`, look for `sum - k`.

```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int sum = 0;
        int count = 0;

        for(int num : nums) {
            sum += num % 2;

            if(freq.find(sum - k) != freq.end()) {
                count += freq[sum - k];
            }

            freq[sum]++;
        }

        return count;
    }
};
```

**Time:** `O(N)`  
**Space:** `O(N)`

## Optimal Approach

- Use the **At Most** technique.
- Count subarrays having at most `k` odd numbers.
- Count subarrays having at most `k - 1` odd numbers.
- Subtract them:

```text
exactly(k) = atMost(k) - atMost(k - 1)
```

```cpp
class Solution {
public:
    int solve(vector<int>& nums, int k) {
        if(k < 0)
            return 0;

        int l = 0;
        int odd = 0;
        int count = 0;

        for(int r = 0; r < nums.size(); r++) {
            odd += nums[r] % 2;

            while(odd > k) {
                odd -= nums[l] % 2;
                l++;
            }

            count += r - l + 1;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
```

**Time:** `O(N)`  
**Space:** `O(1)`

## Key Takeaway

> **Exactly `k` odd numbers = At Most `k` − At Most `k - 1`**

For sliding window, convert each number into:
- **Odd → `1`**
- **Even → `0`**