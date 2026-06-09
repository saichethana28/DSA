/*
Problem: Maximum Total Subarray Value
Platform: LeetCode
Difficulty: Medium

You are given an integer array nums and an integer k.

You need to choose exactly k non-empty subarrays.
Subarrays may overlap, and the same subarray can be chosen multiple times.

Value of a subarray = max(subarray) - min(subarray)

Return the maximum possible total value.

Example 1:
Input: nums = [1,3,2], k = 2
Output: 4

Explanation:
Choose [1,3] -> value = 3 - 1 = 2
Choose [1,3,2] -> value = 3 - 1 = 2
Total = 2 + 2 = 4

Example 2:
Input: nums = [4,2,5,1], k = 3
Output: 12

Explanation:
Choose [4,2,5,1] three times.
Value = 5 - 1 = 4
Total = 4 + 4 + 4 = 12

Constraints:
1 <= nums.length <= 5 * 10^4
0 <= nums[i] <= 10^9
1 <= k <= 10^5
*/


// ------------------------------------------------------------
// Approach 1: Brute Force
// Time Complexity: O(n^3)
// Space Complexity: O(1)
// ------------------------------------------------------------

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        long long best = 0;

        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {

                int mini = INT_MAX;
                int maxi = INT_MIN;

                for(int i = l; i <= r; i++) {
                    mini = min(mini, nums[i]);
                    maxi = max(maxi, nums[i]);
                }

                best = max(best, 1LL * (maxi - mini));
            }
        }

        return best * k;
    }
};


// ------------------------------------------------------------
// Approach 2: Better
// Maintain minimum and maximum while extending subarray.
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// ------------------------------------------------------------

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        long long best = 0;

        for(int l = 0; l < n; l++) {

            int mini = INT_MAX;
            int maxi = INT_MIN;

            for(int r = l; r < n; r++) {

                mini = min(mini, nums[r]);
                maxi = max(maxi, nums[r]);

                best = max(best, 1LL * (maxi - mini));
            }
        }

        return best * k;
    }
};


// ------------------------------------------------------------
// Approach 3: Optimal
// Since we are allowed to choose the same subarray multiple times,
// we only need the maximum value among all subarrays.
//
// The maximum subarray value is simply:
//
// (maximum element in the array) - (minimum element in the array)
//
// Answer = k * (maxElement - minElement)
//
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int num : nums) {
            mini = min(mini, num);
            maxi = max(maxi, num);
        }

        return 1LL * k * (maxi - mini);
    }
};