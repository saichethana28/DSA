/*
LeetCode 451 - Sort Characters By Frequency

Approach:
1. Count the frequency of each character using a hash map.
2. Store (character, frequency) pairs in a vector.
3. Sort the vector in descending order of frequency.
4. Append each character frequency times to the answer.

Time Complexity : O(n + k log k)
Space Complexity: O(k)

where:
n = length of the string
k = number of distinct characters
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        // Count frequency of each character
        for (char c : s) {
            mp[c]++;
        }

        // Store (character, frequency) pairs
        vector<pair<char, int>> freq;
        for (auto &it : mp) {
            freq.push_back(it);
        }

        // Sort by frequency in descending order
        sort(freq.begin(), freq.end(),
             [](const auto &a, const auto &b) {
                 return a.second > b.second;
             });

        string ans;

        // Construct the answer
        for (auto &it : freq) {
            ans += string(it.second, it.first);
        }

        return ans;
    }
};
```
