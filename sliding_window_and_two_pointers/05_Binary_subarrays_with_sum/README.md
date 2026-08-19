# Binary Subarrays With Sum

## Problem Statement

Given a binary array `nums` and an integer `goal`, return the number of non-empty subarrays with sum equal to `goal`.

### Example

```text
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
```

## Brute Force

- Generate all subarrays.
- Calculate their sum.
- If `sum == goal`, increment the count.

**Time:** `O(N²)`  
**Space:** `O(1)`

## Better Approach

- Use **Prefix Sum + HashMap**.
- Store the frequency of every prefix sum.
- For current `sum`, look for `sum - goal`.
- Its frequency tells how many previous subarrays have the required sum.

```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int totalCount = 0;
        int currentSum = 0;

        unordered_map<int, int> freq;

        for(int num : nums) {
            currentSum += num;

            if(currentSum == goal) {
                totalCount++;
            }

            if(freq.find(currentSum - goal) != freq.end()) {
                totalCount += freq[currentSum - goal];
            }

            freq[currentSum]++;
        }

        return totalCount;
    }
};
```

**Time:** `O(N)`  
**Space:** `O(N)`

## Optimal Approach

- Use the **Sliding Window / At Most** technique.
- `solve(nums, goal)` counts subarrays having sum **at most `goal`**.
- Therefore:

```text
exactly(goal) = atMost(goal) - atMost(goal - 1)
```

- `r - l + 1` counts all valid subarrays ending at `r`.

```cpp
class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        if(goal < 0)
            return 0;

        int l = 0;
        int sum = 0;
        int count = 0;

        for(int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while(sum > goal) {
                sum -= nums[l];
                l++;
            }

            count += r - l + 1;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};
```

**Time:** `O(N)`  
**Space:** `O(1)`

## Key Takeaway

> **Exactly `goal` = At Most `goal` − At Most `goal - 1`**

For a binary array, the `atMost` count can be found using a sliding window.