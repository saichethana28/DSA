/*
LeetCode 1021 - Remove Outermost Parentheses

Progression:
1. Find each primitive and copy the inner part.
2. Build the answer while traversing using balance (Optimal).
3. Solve using a stack (works but uses extra space).

Time Complexity:
Approach 1: O(n), Space: O(1)
Approach 2: O(n), Space: O(1)  <-- Best
Approach 3: O(n), Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

/*=========================================================
Approach 1 : Find each primitive and copy its inner part
=========================================================*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        int left = 0;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            if (s[right] == '(')
                count++;
            else
                count--;

            // Primitive completed
            if (count == 0) {

                // Skip first and last character
                for (int i = left + 1; i < right; i++) {
                    ans += s[i];
                }

                left = right + 1;
            }
        }

        return ans;
    }
};


/*=========================================================
Approach 2 : Build answer while traversing (Optimal)
=========================================================*/

// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         int count = 0;
//         string ans = "";
//
//         for (int i = 0; i < s.size(); i++) {
//
//             if (s[i] == '(') {
//
//                 if (count > 0)
//                     ans += s[i];
//
//                 count++;
//
//             } else {
//
//                 count--;
//
//                 if (count > 0)
//                     ans += s[i];
//             }
//         }
//
//         return ans;
//     }
// };


/*=========================================================
Approach 3 : Using Stack
=========================================================*/

// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         stack<char> st;
//         string ans = "";
//
//         for (int i = 0; i < s.size(); i++) {
//
//             if (s[i] == '(') {
//
//                 if (!st.empty())
//                     ans += s[i];
//
//                 st.push(s[i]);
//
//             } else {
//
//                 st.pop();
//
//                 if (!st.empty())
//                     ans += s[i];
//             }
//         }
//
//         return ans;
//     }
// };