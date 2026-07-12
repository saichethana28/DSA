/*
LeetCode 1331 - Rank Transform of an Array

Approach:
1. Copy the original array.
2. Sort the copied array.
3. Remove duplicate elements.
4. Assign each unique value its rank using an unordered_map.
5. Traverse the original array and replace every value with its rank.

Time Complexity : O(N log N)
Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> copy = arr;

        sort(copy.begin(), copy.end());

        copy.erase(unique(copy.begin(), copy.end()), copy.end());

        unordered_map<int, int> rankMap;

        for (int i = 0; i < copy.size(); i++) {
            rankMap[copy[i]] = i + 1;
        }

        vector<int> rank;

        for (int x : arr) {
            rank.push_back(rankMap[x]);
        }

        return rank;
    }
};