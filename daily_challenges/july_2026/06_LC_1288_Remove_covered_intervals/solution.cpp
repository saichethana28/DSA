```cpp
/*
LeetCode 1288 - Remove Covered Intervals

Approach:
1. Sort intervals by:
   - Start in ascending order.
   - If starts are equal, end in descending order.
2. Maintain the maximum ending point seen so far.
3. If the current interval's end is <= maxEnd,
   it is covered.
4. Otherwise, update maxEnd.

Time Complexity : O(n log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](const auto &a, const auto &b) {
                 if (a[0] != b[0]) {
                     return a[0] < b[0];
                 }
                 return a[1] > b[1];
             });

        int n = intervals.size();
        int maxEnd = intervals[0][1];
        int covered = 0;

        for (int i = 1; i < n; i++) {
            if (intervals[i][1] <= maxEnd) {
                covered++;
            }

            maxEnd = max(maxEnd, intervals[i][1]);
        }

        return n - covered;
    }
};
```
