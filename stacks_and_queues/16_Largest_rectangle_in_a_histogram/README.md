# Largest Rectangle in Histogram

## Problem Statement

Given an array `heights` where each element represents the height of a histogram bar and each bar has width `1`, return the area of the largest rectangle that can be formed in the histogram.

### Example

Input: `heights = [2,1,5,6,2,3]`

Output: `10`

Explanation:

The largest rectangle is formed by heights `5` and `6`.

`width = 2`

`height = 5`

`area = 5 × 2 = 10`

---

## Brute Force Approach

### Algorithm

1. Fix the starting index `i`.
2. Extend the ending index `j`.
3. Maintain the minimum height in the current range.
4. Calculate `area = minHeight × width`.
5. Keep track of the maximum area.

### Complexity

- Time: `O(N²)`
- Space: `O(1)`

---

## Optimised Approach 1 — PSE + NSE

### Algorithm

1. Find the Previous Smaller Element (PSE) index for every bar.
2. Find the Next Smaller Element (NSE) index for every bar.
3. For every bar, calculate the maximum width using its PSE and NSE.
4. `width = NSE[i] - PSE[i] - 1`
5. `area = heights[i] × width`
6. Take the maximum area.

### Code

class Solution {
public:
    vector<int> NSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if(st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> PSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if(st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;

        vector<int> pse = PSE(heights);
        vector<int> nse = NSE(heights);

        for(int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = width * heights[i];

            ans = max(ans, area);
        }

        return ans;
    }
};

### Complexity

- Time: `O(N)`
- Space: `O(N)`

---

## Optimised Approach 2 — Single Monotonic Stack

### Algorithm

1. Maintain a monotonic increasing stack of indices.
2. Traverse the histogram from left to right.
3. When the current height is smaller than or equal to the stack top, pop the stack.
4. The current index becomes the Next Smaller Element of the popped bar.
5. After popping, the new stack top becomes the Previous Smaller Element.
6. Calculate `width = right - left - 1`.
7. Calculate the area and update the maximum.
8. After traversal, process remaining bars using `n` as their right boundary.

### Code

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        int n = heights.size();

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                int h = heights[st.top()];
                st.pop();

                if(st.empty()) {
                    int area = h * (i - (-1) - 1);
                    ans = max(ans, area);
                }
                else {
                    int area = h * (i - st.top() - 1);
                    ans = max(ans, area);
                }
            }

            st.push(i);
        }

        while(!st.empty()) {
            int h = heights[st.top()];
            st.pop();

            if(st.empty()) {
                int area = h * (n - (-1) - 1);
                ans = max(ans, area);
            }
            else {
                int area = h * (n - st.top() - 1);
                ans = max(ans, area);
            }
        }

        return ans;
    }
};

### Complexity

- Time: `O(N)`
- Space: `O(N)`

---

## Key Takeaways

- For every bar, treat its height as the limiting height of a rectangle.
- PSE and NSE determine how far that bar can extend.
- `width = NSE - PSE - 1`.
- In the single-stack approach, popping a bar means its right boundary has been found.
- After popping, the new stack top gives its left boundary.
- Remaining stack elements use `n` as their right boundary.
- The single-stack approach calculates boundaries and areas together.