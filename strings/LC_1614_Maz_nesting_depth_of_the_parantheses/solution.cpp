```cpp id="r9ow4m"
/*
LeetCode 1614 - Maximum Nesting Depth of the Parentheses

Approach:
- Maintain a counter to represent the current nesting depth.
- Increment the counter for every '('.
- Update the maximum depth.
- Decrement the counter for every ')'.

Time Complexity : O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                count++;
                maxi = max(maxi, count);
            }
            else if (c == ')') {
                count--;
            }
        }

        return maxi;
    }
};
```
