# Single Number III

## Problem Statement

Given an integer array `nums`, exactly **two elements appear only once** and all the other elements appear **exactly twice**.

Find and return the two unique numbers.

You may return the answer in any order.

### Example 1

**Input**
```
nums = [1,2,1,3,2,5]
```

**Output**
```
[3,5]
```

**Explanation**

```
1 appears twice.
2 appears twice.

3 and 5 appear only once.
```

---

### Example 2

**Input**
```
nums = [-1,0]
```

**Output**
```
[-1,0]
```

---

# Brute Force Approach

## Approach

For every element:

- Count its frequency by traversing the entire array.
- If its frequency is `1`, add it to the answer.

## Code

```cpp
vector<int> singleNumber(vector<int>& nums) {

    vector<int> ans;

    for(int i = 0; i < nums.size(); i++) {

        int cnt = 0;

        for(int j = 0; j < nums.size(); j++) {
            if(nums[i] == nums[j])
                cnt++;
        }

        if(cnt == 1)
            ans.push_back(nums[i]);
    }

    return ans;
}
```

## Complexity Analysis

- **Time Complexity:** `O(N²)`
- **Space Complexity:** `O(1)` (excluding output array)

---

# Better Approach (HashMap)

## Approach

- Store the frequency of every element using a hash map.
- Traverse the map.
- Store every element having frequency `1`.

## Code

```cpp
vector<int> singleNumber(vector<int>& nums) {

    unordered_map<int,int> mp;

    for(int num : nums)
        mp[num]++;

    vector<int> ans;

    for(auto it : mp) {
        if(it.second == 1)
            ans.push_back(it.first);
    }

    return ans;
}
```

## Complexity Analysis

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(N)`

---

# Optimal Approach

## Key Observation

If we XOR every element of the array,

all duplicate numbers cancel each other.

```
x ^ x = 0
```

Finally,

```
xorAll = unique1 ^ unique2
```

Since the two unique numbers are different,

their XOR must contain at least one set bit.

That set bit tells us that the two unique numbers differ at that bit position.

For example,

```
unique1 = 3

011
```

```
unique2 = 5

101
```

```
011
101
---
110
```

The rightmost set bit in `110` indicates a position where the two numbers differ.

Now partition the entire array into two groups based on that bit.

Group 1:
- Numbers having that bit set.

Group 2:
- Numbers having that bit unset.

All duplicate numbers always fall into the **same group**, so they cancel each other after XOR.

The two unique numbers fall into **different groups**, leaving one unique number in each group.

## Approach

- XOR all elements to obtain:

```
xorAll = unique1 ^ unique2
```

- Find the rightmost set bit using

```
mask = xorAll & (-xorAll)
```

- Traverse the array.
- Partition every element into two groups:
  - `(num & mask) != 0`
  - `(num & mask) == 0`
- XOR each group separately.
- Return the two remaining numbers.

## Code

```cpp
vector<int> singleNumber(vector<int>& nums) {

    int xorAll = 0;

    for(int num : nums)
        xorAll ^= num;

    int mask = xorAll & (-xorAll);

    int num1 = 0;
    int num2 = 0;

    for(int num : nums) {

        if(num & mask)
            num1 ^= num;
        else
            num2 ^= num;
    }

    return {num1, num2};
}
```

## Complexity Analysis

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(1)`

---

# Interview Notes

- This is one of the most important XOR interview problems.
- The key idea is **partitioning** using a bit where the two unique numbers differ.
- `xorAll & (-xorAll)` extracts the rightmost set bit in constant time.
- Duplicate numbers always belong to the same partition and cancel each other.
- This technique is commonly asked in interviews because it combines multiple bit manipulation concepts.

---

# What I Learned ⭐

- XOR of the entire array gives `unique1 ^ unique2`.
- The rightmost set bit identifies a position where the two unique numbers differ.
- Partitioning the array using that bit separates the two unique numbers into different groups.
- XOR within each group removes duplicates and leaves one unique number.
- The trick `n & (-n)` is extremely useful for partition-based XOR problems.