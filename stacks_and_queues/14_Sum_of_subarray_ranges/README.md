# Sum of Subarray Ranges

## Problem Statement

Given an integer array `nums`, the range of a subarray is the difference between its largest and smallest element.

Return the sum of the ranges of all possible contiguous non-empty subarrays.

### Example

Input: `nums = [1,2,3]`

Output: `4`

Explanation:

- `[1]` → range = `0`
- `[2]` → range = `0`
- `[3]` → range = `0`
- `[1,2]` → range = `1`
- `[2,3]` → range = `1`
- `[1,2,3]` → range = `2`

Total = `4`

---

## Key Observation

For every subarray:

`Range = Maximum - Minimum`

Therefore:

`Sum of Subarray Ranges = Sum of Subarray Maximums - Sum of Subarray Minimums`

So, for every element, calculate:

- Its contribution when it acts as the maximum.
- Its contribution when it acts as the minimum.

---

## Approach — Monotonic Stack

### Algorithm

1. Find the Next Greater Element (NGE) index for every element.
2. Find the Previous Greater Element (PGE) index for every element.
3. Find the Next Smaller Element (NSE) index for every element.
4. Find the Previous Smaller Element (PSE) index for every element.
5. Calculate the number of subarrays where `nums[i]` is the maximum:
   `maxLeft * maxRight`
6. Calculate the number of subarrays where `nums[i]` is the minimum:
   `minLeft * minRight`
7. Calculate the maximum and minimum contributions.
8. Return `totalMaximum - totalMinimum`.

---

## Contribution Formula

For every index `i`:

`maxLeft = i - PGE[i]`

`maxRight = NGE[i] - i`

`maxContribution = nums[i] * maxLeft * maxRight`

Similarly:

`minLeft = i - PSE[i]`

`minRight = NSE[i] - i`

`minContribution = nums[i] * minLeft * minRight`

Finally:

`Answer = Sum of Maximum Contributions - Sum of Minimum Contributions`

---

## Duplicate Handling

Use asymmetric comparisons to avoid double-counting equal elements.

### Maximum

NGE:
`pop while nums[st.top()] <= nums[i]`

PGE:
`pop while nums[st.top()] < nums[i]`

### Minimum

NSE:
`pop while nums[st.top()] >= nums[i]`

PSE:
`pop while nums[st.top()] > nums[i]`

---

## Code

```cpp
class Solution {
public:
    vector<int> findNGE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> findPGE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> findNSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> findPSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> pse = findPSE(nums);
        vector<int> nse = findNSE(nums);
        vector<int> pge = findPGE(nums);
        vector<int> nge = findNGE(nums);

        long long maxi = 0;
        long long mini = 0;

        for (int i = 0; i < n; i++) {
            int maxLeft = i - pge[i];
            int minLeft = i - pse[i];

            int maxRight = nge[i] - i;
            int minRight = nse[i] - i;

            long long maxFreq = 1LL * maxLeft * maxRight;
            long long minFreq = 1LL * minLeft * minRight;

            long long maxContribution = maxFreq * nums[i];
            long long minContribution = minFreq * nums[i];

            maxi += maxContribution;
            mini += minContribution;
        }

        return maxi - mini;
    }
};
```
## Complexity

- Time: `O(N)`
- Space: `O(N)`

Each element is pushed and popped at most once in each monotonic stack.

---

## Key Takeaways

- Range = Maximum - Minimum.
- Calculate total subarray maximums separately.
- Calculate total subarray minimums separately.
- Use PGE/NGE for maximum contributions.
- Use PSE/NSE for minimum contributions.
- Contribution = `value * leftChoices * rightChoices`.
- Use asymmetric comparisons to handle duplicate values.
- This is an extension of the Sum of Subarray Minimums pattern.