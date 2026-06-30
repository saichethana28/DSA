/*
LeetCode 151 - Reverse Words in a String

Approach 1: Store all words in a vector, then traverse in reverse.
Time  : O(n)
Space : O(n)

Approach 2: Two Pointers (Better)
Time  : O(n)
Space : O(n) (answer string only)

Progression:
1. Extract and store all words.
2. Observe that storing words is unnecessary.
3. Traverse from the end using two pointers and directly build the answer.
*/

#include <bits/stdc++.h>
using namespace std;

/*=========================================================
Approach 1 : Store Words in a Vector
=========================================================*/

// class Solution {
// public:
//     string reverseWords(string s) {
//         vector<string> words;
//         string word = "";
//
//         for (char c : s) {
//             if (c == ' ') {
//                 if (!word.empty()) {
//                     words.push_back(word);
//                     word = "";
//                 }
//             } else {
//                 word += c;
//             }
//         }
//
//         if (!word.empty()) {
//             words.push_back(word);
//         }
//
//         string ans = "";
//
//         for (int i = words.size() - 1; i >= 0; i--) {
//             ans += words[i];
//
//             if (i != 0) {
//                 ans += " ";
//             }
//         }
//
//         return ans;
//     }
// };


/*=========================================================
Approach 2 : Two Pointers (Better)
=========================================================*/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int right = n - 1;
        int left = n - 1;

        string ans = "";

        while (right >= 0) {

            // Skip trailing/multiple spaces
            while (right >= 0 && s[right] == ' ') {
                right--;
            }

            if (right < 0)
                break;

            left = right;

            // Find the beginning of the current word
            while (left >= 0 && s[left] != ' ') {
                left--;
            }

            // Append the current word
            ans += s.substr(left + 1, right - left);
            ans += ' ';

            // Move to the previous word
            right = left;
        }

        // Remove the last extra space
        ans.pop_back();

        return ans;
    }
};