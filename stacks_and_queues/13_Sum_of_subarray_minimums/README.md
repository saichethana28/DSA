# Sum of Subarray Minimums

## Problem Statement

Given an array `arr`, find the sum of the minimum element of every possible contiguous subarray.

### Example

Input: `arr = [3,1,2]`

Output: `9`

## What I Understand

Instead of generating every subarray, find how many subarrays have each element as their minimum.

## Brute Force Approach

### Algorithm

1. Generate every possible contiguous subarray.
2. Maintain the minimum while extending the subarray.
3. Add the minimum of every subarray to the answer.
4. This takes O(N²) time.

My initial recursion generated subsequences instead of subarrays because take/not-take choices do not guarantee contiguity.

## Complexity

- Time: O(N²)
- Space: O(N)

## Optimal Approach — Monotonic Stack

### Algorithm

1. Find the Next Smaller Element (NSE) index for every element.
2. Find the Previous Smaller Element (PSE) index for every element.
3. Calculate `left = i - PSE[i]` and `right = NSE[i] - i`.
4. Number of subarrays where `arr[i]` is minimum = `left * right`.
5. Add `arr[i] * left * right` to the answer.

### Duplicate Handling

- PSE: pop while `arr[st.top()] > arr[i]`.
- NSE: pop while `arr[st.top()] >= arr[i]`.
- This handles duplicate values without double-counting.

### Code

class Solution {
public:
    const int mod = 1e9 + 7;

    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top();
            } else {
                ans[i] = n;
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> findPSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top();
            } else {
                ans[i] = -1;
            }

            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);

        long long ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            long long contribution =
                1LL * arr[i] * left * right;

            ans = (ans + contribution) % mod;
        }

        return ans;
    }
};

## Complexity

- Time: O(N)
- Space: O(N)

## Key Takeaways

- Think about each element's contribution instead of generating every subarray.
- PSE and NSE give the boundaries where an element can remain the minimum.
- `left * right` gives the number of subarrays where `arr[i]` is the minimum.
- Use different inequalities for PSE and NSE to handle duplicate values correctly.