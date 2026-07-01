```cpp
/*
LeetCode 205 - Isomorphic Strings

Approach:
1. Maintain two hash maps.
2. sToT checks that every character in s always maps to the same character in t.
3. tToS ensures that no two different characters in s map to the same character in t.

Time Complexity : O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for (int i = 0; i < s.size(); i++) {

            // Check mapping from s -> t
            if (sToT.count(s[i])) {
                if (sToT[s[i]] != t[i]) {
                    return false;
                }
            } else {
                sToT[s[i]] = t[i];
            }

            // Check mapping from t -> s
            if (tToS.count(t[i])) {
                if (tToS[t[i]] != s[i]) {
                    return false;
                }
            } else {
                tToS[t[i]] = s[i];
            }
        }

        return true;
    }
};
```
