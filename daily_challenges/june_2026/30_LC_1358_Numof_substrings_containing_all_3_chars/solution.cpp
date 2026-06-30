//Brute force
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            mp.clear();
            for (int j = i; j < s.size(); j++) {
                mp[s[j]]++;
                if (mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};


//optimal
class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[3]={0};
        int n=s.size();
        int ans=0;
        int left=0;
        for(int right=0;right<n;right++){
            freq[s[right]-'a']++;
            while(freq[0]>=1 && freq[1]>=1 && freq[2]>=1){
                ans+=n-right;
                freq[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};