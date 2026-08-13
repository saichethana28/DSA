# Sliding Window Maximum

## Problem Statement

Given an array `nums` and a sliding window of size `k` moving from left to right, return the maximum element in every window.

### Example

Input:

`nums = [1,3,-1,-3,5,3,6,7]`

`k = 3`

Output:

`[3,3,5,5,6,7]`

---

## Brute Force Approach

### Algorithm

1. Start a window of size `k`.
2. Traverse all `k` elements and find the maximum.
3. Move the window one position to the right.
4. Repeat until all windows are processed.

### Complexity

- Time: `O(N × K)`
- Space: `O(N)` for the answer.

---

## Optimal Approach — Monotonic Deque

### Key Observation

Maintain a deque of indices where the corresponding values are in **decreasing order**.

The front of the deque always contains the index of the maximum element in the current window.

### Algorithm

1. Traverse the array from left to right.
2. Remove the front index if it is outside the current window.
3. Remove elements from the back while their values are smaller than or equal to the current element.
4. Push the current index into the deque.
5. Once the first window is formed, `nums[dq.front()]` is the maximum.
6. Add the maximum to the answer.

### Why Store Indices?

We need indices to determine whether an element has left the sliding window.

For a current index `i`, the window contains:

`[i-k+1 ... i]`

So an index `<= i-k` is expired.

### Deque Structure

The deque maintains values in decreasing order:

`front → largest → smaller → smaller → smallest ← back`

- **Front:** current maximum
- **Back:** where new elements are inserted
- Remove expired elements from the front.
- Remove smaller/useless elements from the back.

---

## Code

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for(int i = 0; i < n; i++) {

            // Remove expired index
            if(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller or equal elements
            while(!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Add current index
            dq.push_back(i);

            // Window is ready
            if(i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
```

---

## Complexity

- Time: `O(N)`
- Space: `O(K)`

Each index is pushed into the deque once and removed at most once.

---

## Key Takeaways

- Sliding Window Maximum → **Monotonic Decreasing Deque**
- Store **indices**, not values.
- Front of deque always gives the current maximum.
- Remove expired indices from the front.
- Remove smaller/equal elements from the back.
- Each element enters and leaves the deque at most once.
- Overall time complexity is `O(N)`.