```cpp
/*
LeetCode 242 - Valid Anagram

Approach 1: Hash Map
- Count frequencies using an unordered_map.
- Increment for s and decrement for t.
- If every frequency becomes zero, the strings are anagrams.

Time Complexity : O(n)
Space Complexity: O(k)

---------------------------------------------------------

Approach 2: Frequency Array (Optimized)
- Since only lowercase English letters are present,
  use an array of size 26.
- Increment frequencies for s.
- Decrement frequencies for t.
- Verify that every frequency is zero.

Time Complexity : O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

/*=========================================================
Approach 1 : Hash Map
=========================================================*/

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size()) {
//             return false;
//         }
//
//         unordered_map<char, int> freq;
//
//         for (char c : s) {
//             freq[c]++;
//         }
//
//         for (char c : t) {
//             freq[c]--;
//         }
//
//         for (auto &it : freq) {
//             if (it.second != 0) {
//                 return false;
//             }
//         }
//
//         return true;
//     }
// };

/*=========================================================
Approach 2 : Frequency Array (Optimized)
=========================================================*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (char c : t) {
            freq[c - 'a']--;
        }

        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};
```
