# Maximum Points You Can Obtain from Cards

## Problem Statement

Given an array `cardPoints` and an integer `k`, choose exactly `k` cards from either the beginning or the end of the array. Return the maximum score possible.

### Example

```text
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
```

## Brute Force

- Try every possible combination of taking `x` cards from the left and `k-x` cards from the right.
- Calculate the sum for each combination.
- Return the maximum sum.

**Time:** `O(K)`  
**Space:** `O(1)`

## Optimal Approach

- Initially take all `k` cards from the left.
- Then gradually remove one card from the left and add one card from the right.
- Keep updating the maximum sum.

```cpp
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int leftsum = 0;
        int rightsum = 0;
        int maxsum = 0;

        for(int i = 0; i < k; i++) {
            leftsum += cardPoints[i];
        }

        maxsum = leftsum;

        for(int i = k - 1; i >= 0; i--) {
            leftsum -= cardPoints[i];
            rightsum += cardPoints[n - k + i];

            maxsum = max(maxsum, leftsum + rightsum);
        }

        return maxsum;
    }
};
```

**Time:** `O(K)`  
**Space:** `O(1)`

## Key Takeaway

> Start with all `k` cards from the left, then move the selection one card at a time from **left → right** while checking the maximum sum.