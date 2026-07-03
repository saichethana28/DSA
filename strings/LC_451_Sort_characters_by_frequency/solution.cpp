```cpp
/*
LeetCode 451 - Sort Characters By Frequency

Approach 1 : Frequency Array
- Count frequency using an array.
- Store frequency and corresponding character index.
- Sort by frequency.
- Construct the answer.

Time Complexity : O(n + k log k)
Space Complexity: O(k)

---------------------------------------------------------

Approach 2 : Hash Map (Cleaner)
- Count frequencies using unordered_map.
- Store (character, frequency) pairs in a vector.
- Sort by descending frequency.
- Build the answer string.

Time Complexity : O(n + k log k)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

/*=========================================================
Approach 1 : Frequency Array
=========================================================*/

// class Solution {
// public:
//     string frequencySort(string s) {
//         vector<pair<int, int>> freq(122 - 48 + 1, {0, 0});
//         string ans;
//
//         for (char c : s) {
//             freq[c - '0'].first++;
//             freq[c - '0'].second = c - '0';
//         }
//
//         sort(freq.begin(), freq.end(),
//              [](const auto &a, const auto &b) {
//                  return a.first > b.first;
//              });
//
//         for (auto &it : freq) {
//             char ch = it.second + '0';
//             int count = it.first;
//
//             if (count > 0) {
//                 ans += string(count, ch);
//             }
//         }
//
//         return ans;
//     }
// };

/*=========================================================
Approach 2 : Hash Map (Optimized & Cleaner)
=========================================================*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        vector<pair<char, int>> freq(mp.begin(), mp.end());

        sort(freq.begin(), freq.end(),
             [](const auto &a, const auto &b) {
                 return a.second > b.second;
             });

        string ans;

        for (auto &it : freq) {
            ans += string(it.second, it.first);
        }

        return ans;
    }
};
```
