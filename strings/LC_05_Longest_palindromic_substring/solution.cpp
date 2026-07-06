```cpp id="y74qjv"
/*
LeetCode 5 - Longest Palindromic Substring

Approach:
- Every palindrome has a center.
- For each index:
    1. Expand around (i, i) for odd-length palindromes.
    2. Expand around (i, i + 1) for even-length palindromes.
- Keep track of the longest palindrome found.

Time Complexity : O(n²)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;
        string ans = "";

        for (int i = 0; i < n; i++) {

            // Odd-length palindrome
            int left = i;
            int right = i;

            while (left >= 0 && right < n) {
                if (s[left] != s[right]) {
                    break;
                }

                if (right - left + 1 > maxLen) {
                    maxLen = right - left + 1;
                    ans = s.substr(left, maxLen);
                }

                left--;
                right++;
            }

            // Even-length palindrome
            left = i;
            right = i + 1;

            while (left >= 0 && right < n) {
                if (s[left] != s[right]) {
                    break;
                }

                if (right - left + 1 > maxLen) {
                    maxLen = right - left + 1;
                    ans = s.substr(left, maxLen);
                }

                left--;
                right++;
            }
        }

        return ans;
    }
};
```
