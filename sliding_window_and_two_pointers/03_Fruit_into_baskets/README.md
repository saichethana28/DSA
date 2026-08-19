# Fruit Into Baskets

## Problem Statement

Given an array `fruits`, find the length of the longest contiguous subarray containing at most **2 mp.size() types of fruits**.

## Brute Force

- Generate all subarrays.
- Count mp.size() fruit types.
- If mp.size() types `> 2`, stop.
- Update the maximum length.

**Time:** `O(N²)`  
**Space:** `O(N)`

## Better Approach

- Use **Sliding Window + HashMap**.
- Expand `r`.
- If `mp.size() > 2`, shrink using `while` until the window becomes valid.
- Update the maximum length.

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0,r=0,maxlen=0;
        unordered_map<int,int>mp;
        while(r<n){
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);
            r++;
        }
        return maxlen;
    }
};
```

**Time:** `O(N)`  
**Space:** `O(N)`

## Optimal Approach

- Since we only need the **maximum length**, we don't need to shrink until the window is fully valid.
- If `mp.size() > 2`, shrink **only once** using `if`.
- Continue expanding `r`.

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0,r=0,maxlen=0;
        unordered_map<int,int>mp;
        while(r<n){
            mp[fruits[r]]++;
            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);
            r++;
        }
        return maxlen;
    }
};
```

**Time:** `O(N)`  
**Space:** `O(N)`

## Key Takeaway

> **Better:** `while` → make the window fully valid.  
> **Optimal:** `if` → shrink only once because we only care about the maximum length.