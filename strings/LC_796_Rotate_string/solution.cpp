```cpp
/*
LeetCode 796 - Rotate String

Approach 1: Brute Force
- Perform every possible left rotation.
- Compare the rotated string with the goal.

Time Complexity : O(n²)
Space Complexity: O(n)

---------------------------------------------------------

Approach 2: Optimized
- Concatenate the string with itself.
- Every rotation of s appears as a substring of s + s.
- Check if goal exists in the concatenated string.

Time Complexity : O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

/*=========================================================
Approach 1 : Brute Force
=========================================================*/

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if (s.size() != goal.size()) {
//             return false;
//         }
//
//         int n = s.size();
//
//         while (n--) {
//             s = s.substr(1) + s[0];
//
//             if (s == goal) {
//                 return true;
//             }
//         }
//
//         return false;
//     }
// };

/*=========================================================
Approach 2 : Optimized
=========================================================*/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        string combined = s + s;

        return combined.find(goal) != string::npos;
    }
};
```
