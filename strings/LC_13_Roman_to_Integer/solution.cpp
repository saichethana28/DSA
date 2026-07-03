```cpp
/*
LeetCode 13 - Roman to Integer

Approach:
- Store the value of each Roman numeral.
- Start from the last character.
- Traverse from right to left.
- If the current value is greater than or equal to the next value,
  add it to the answer.
- Otherwise, subtract it.

Time Complexity : O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int n = s.size();
        int num = mp[s[n - 1]];

        for (int i = n - 2; i >= 0; i--) {
            if (mp[s[i]] >= mp[s[i + 1]]) {
                num += mp[s[i]];
            } else {
                num -= mp[s[i]];
            }
        }

        return num;
    }
};
```
