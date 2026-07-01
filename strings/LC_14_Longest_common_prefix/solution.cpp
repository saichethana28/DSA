/*
LeetCode 14 - Longest Common Prefix

Approach:
1. Take the first string as the current common prefix.
2. Compare it with every remaining string.
3. Store matching characters until a mismatch occurs.
4. Update the common prefix.
5. If the prefix becomes empty, return immediately.

Time Complexity : O(S)
Space Complexity: O(S)

where S is the total number of characters across all strings.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string compare = strs[0];
        string prefix = "";

        int n = strs.size();

        for (int i = 1; i < n; i++) {
            int mini = min(compare.size(), strs[i].size());

            for (int j = 0; j < mini; j++) {
                if (compare[j] == strs[i][j]) {
                    prefix += strs[i][j];
                } else {
                    break;
                }
            }

            compare = prefix;

            if (compare.empty()) {
                return "";
            }

            prefix = "";
        }

        return compare;
    }
};