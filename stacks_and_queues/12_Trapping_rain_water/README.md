# Trapping Rain Water

## Problem Statement

Given an array `height` where each element represents the height of a bar, return the total amount of rainwater that can be trapped between the bars.

### Example

Input: `height = [0,1,0,2,1,0,1,3,2,1,2,1]`

Output: `6`

## What I Understand

For every index, trapped water depends on the maximum height on its left and right.

## Approach — Two Pointers

### Algorithm

1. Keep two pointers `l` and `r` at both ends of the array.
2. Maintain `leftMax` and `rightMax` seen so far.
3. Process the side having the smaller height and calculate trapped water.
4. Move that pointer inward until both pointers meet.

### Code
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;

        while (l <= r) {
            if (height[l] <= height[r]) {
                leftMax = max(leftMax, height[l]);
                ans += leftMax - height[l];
                l++;
            } else {
                rightMax = max(rightMax, height[r]);
                ans += rightMax - height[r];
                r--;
            }
        }

        return ans;
    }
};
```
## Complexity

- Time: O(N)
- Space: O(1)

## Key Takeaways

- Trapped water depends on the maximum heights on both sides.
- Two pointers avoid using separate left-max and right-max arrays.
- Process the side with the smaller boundary height.
- Maintain `leftMax` and `rightMax` while moving the pointers.