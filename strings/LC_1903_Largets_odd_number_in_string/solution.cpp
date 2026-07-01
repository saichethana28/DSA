/*
LeetCode 1903 - Largest Odd Number in String

Approach:
1. Traverse the string from right to left.
2. Find the first odd digit.
3. Return the prefix ending at that digit.

Time Complexity : O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();

        for (int i = n - 1; i >= 0; i--) {
            int digit = num[i] - '0';

            if (digit % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};