/*
Problem: Earliest Second to Mark Indices I
Platform: LeetCode 3048
Difficulty: Medium

You are given two 1-indexed integer arrays nums and changeIndices.

Initially, all indices are unmarked.

At each second s (1 <= s <= m), you may perform exactly one operation:

1. Decrement any nums[i] by 1.
2. If nums[changeIndices[s]] == 0, mark index changeIndices[s].
3. Do nothing.

Return the earliest second when all indices can be marked,
or -1 if it is impossible.

------------------------------------------------------------

Example 1:

Input:
nums = [2,2,0]
changeIndices = [2,2,2,2,3,2,2,1]

Output:
8

------------------------------------------------------------

Example 2:

Input:
nums = [1,3]
changeIndices = [1,1,1,2,1,1,1]

Output:
6

------------------------------------------------------------

Example 3:

Input:
nums = [0,1]
changeIndices = [2,2,2]

Output:
-1

------------------------------------------------------------

Constraints:

1 <= n <= 2000
1 <= m <= 2000
0 <= nums[i] <= 10^9

*/


// ============================================================
// Approach 1: Binary Search + Deadline Scheduling
// ============================================================
//
// Idea:
//
// Binary search the answer.
//
// For a given prefix [0...idx], determine whether all indices
// can be marked.
//
// Observation:
//
// Each index should be marked at its LAST occurrence.
//
// Missing the last occurrence means that index can never be marked.
//
// ------------------------------------------------------------
//
// Let:
//
// sumvalues = total decrement operations already used
//
// cntmarked = number of indices already marked
//
// Suppose current index x has deadline t.
//
// Current index requires:
//
//      nums[x-1] decrement operations
//      1 marking operation at time t
//
// Therefore:
//
// Available time before marking x:
//
//      t - sumvalues - cntmarked - 1
//
// If:
//
//      availableTime < nums[x-1]
//
// then impossible.
//
// Otherwise:
//
//      sumvalues += nums[x-1]
//      cntmarked++
//
// ------------------------------------------------------------
//
// Time Complexity:
//
// canfinishby() : O(n log n)
// Binary Search : O(log m)
//
// Overall:
//
// O(n log n log m)
//
// Space Complexity:
//
// O(n)
// ============================================================

class Solution {
public:

    bool canfinishby(int idx,
                     vector<int>& nums,
                     vector<int>& changeIndices) {

        int n = nums.size();

        int sumvalues = 0;
        int cntmarked = 0;

        vector<int> lastocc(n + 1, 0);
        vector<pair<int,int>> deadlines;

        // Find last occurrence of each index
        for(int i = 0; i <= idx; i++) {
            lastocc[changeIndices[i]] = i + 1;
        }

        // Every index should appear at least once
        for(int i = 1; i <= n; i++) {

            if(lastocc[i] == 0)
                return false;

            deadlines.push_back({lastocc[i], i});
        }

        // Process indices in order of deadlines
        sort(deadlines.begin(), deadlines.end());

        for(auto &it : deadlines) {

            int t = it.first;
            int x = it.second;

            // Available decrement slots
            if(t - sumvalues - cntmarked - 1 < nums[x - 1])
                return false;

            sumvalues += nums[x - 1];
            cntmarked++;
        }

        return true;
    }

    int earliestSecondToMarkIndices(vector<int>& nums,
                                    vector<int>& changeIndices) {

        int m = changeIndices.size();

        int low = 0;
        int high = m - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(canfinishby(mid, nums, changeIndices))
                high = mid - 1;
            else
                low = mid + 1;
        }

        if(low == m)
            return -1;

        return low + 1;
    }
};


/*
// ============================================================
// Approach 2: Binary Search + Greedy (Optimal)
// ============================================================
//
// Observation:
//
// Mark every index at its LAST occurrence.
//
// While traversing the seconds:
//
// If current second is NOT the last occurrence:
//
//      freeTime++
//
// because this second can be used for decrement operations.
//
// If current second IS the last occurrence:
//
// We must mark this index now.
//
// Before marking it, we must already have completed
// nums[idx] decrement operations.
//
// Therefore:
//
//      if(freeTime < nums[idx])
//              impossible
//
//      else
//              freeTime -= nums[idx]
//
// ------------------------------------------------------------
//
// Time Complexity:
//
// canMark() : O(m)
//
// Binary Search : O(log m)
//
// Overall:
//
// O(m log m)
//
// Space Complexity:
//
// O(n)
//
// ============================================================


class Solution {
public:

    bool canMark(int limit,
                 vector<int>& nums,
                 vector<int>& changeIndices) {

        int n = nums.size();

        vector<int> last(n, -1);

        // Find last occurrence inside first 'limit' seconds
        for(int second = 0; second < limit; second++) {

            int idx = changeIndices[second] - 1;

            last[idx] = second;
        }

        // Some index never appeared
        for(int i = 0; i < n; i++) {

            if(last[i] == -1)
                return false;
        }

        long long freeTime = 0;

        for(int second = 0; second < limit; second++) {

            int idx = changeIndices[second] - 1;

            // Must mark this index now
            if(last[idx] == second) {

                if(freeTime < nums[idx])
                    return false;

                freeTime -= nums[idx];
            }

            // Available for decrement operations
            else {

                freeTime++;
            }
        }

        return true;
    }

    int earliestSecondToMarkIndices(vector<int>& nums,
                                    vector<int>& changeIndices) {

        int m = changeIndices.size();

        int left = 1;
        int right = m;

        int answer = -1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(canMark(mid, nums, changeIndices)) {

                answer = mid;

                right = mid - 1;
            }
            else {

                left = mid + 1;
            }
        }

        return answer;
    }
};

*/


/*
============================================================
Summary
============================================================

Approach 1:
Binary Search + Deadline Scheduling

Maintain:

    sumvalues
    cntmarked

Sort indices by their deadlines and check whether enough
time exists before each deadline.

Time Complexity:

    O(n log n log m)


------------------------------------------------------------

Approach 2:
Binary Search + Greedy (Optimal)

Maintain:

    freeTime

Each non-last occurrence contributes one decrement slot.

Each last occurrence consumes nums[idx] decrement slots
and performs the mark.

Time Complexity:

    O(m log m)

============================================================
*/