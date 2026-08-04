# Single Number I

## Problem Statement

Given a non-empty integer array `nums`, every element appears **exactly twice** except for **one element**, which appears only once.

Find and return that single element.

You must solve it using **linear time** and **constant extra space**.

### Example 1

**Input**
```
nums = [2,2,1]
```

**Output**
```
1
```

**Explanation**

```
2 appears twice.
1 appears only once.
```

Therefore, the answer is `1`.

---

### Example 2

**Input**
```
nums = [4,1,2,1,2]
```

**Output**
```
4
```

---

# Brute Force Approach

## Approach

For every element:

- Count its frequency by traversing the entire array.
- If the frequency is `1`, return that element.

## Code

```cpp
int singleNumber(vector<int>& nums) {
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        int cnt = 0;

        for(int j = 0; j < n; j++) {
            if(nums[i] == nums[j])
                cnt++;
        }

        if(cnt == 1)
            return nums[i];
    }

    return -1;
}
```

## Complexity Analysis

- **Time Complexity:** `O(N²)`
- **Space Complexity:** `O(1)`

---

# Better Approach (HashMap)

## Approach

- Store the frequency of every element using a hash map.
- Traverse the map.
- Return the element whose frequency is `1`.

## Code

```cpp
int singleNumber(vector<int>& nums) {
    unordered_map<int,int> mp;

    for(int num : nums)
        mp[num]++;

    for(auto it : mp) {
        if(it.second == 1)
            return it.first;
    }

    return -1;
}
```

## Complexity Analysis

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(N)`

---

# Optimal Approach

## Key Observation

XOR has two important properties:

```
x ^ x = 0

x ^ 0 = x
```

Since every element appears exactly twice,

every duplicate pair cancels itself.

Only the unique element remains.

Example:

```
2 ^ 2 ^ 1

↓

0 ^ 1

↓

1
```

## Approach

- Initialize the answer as `0`.
- XOR every element in the array.
- Return the final XOR value.

## Code

```cpp
int singleNumber(vector<int>& nums) {
    int ans = 0;

    for(int num : nums)
        ans ^= num;

    return ans;
}
```

## Complexity Analysis

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(1)`

---

# Interview Notes

- One of the most frequently asked XOR interview questions.
- The solution relies on the cancellation property of XOR.
- Whenever every element appears exactly twice except one, XOR should immediately come to mind.

---

# What I Learned ⭐

- XOR eliminates duplicate values efficiently.
- No extra space is required.
- Bit manipulation can replace frequency counting in many interview problems.
- The XOR cancellation property forms the foundation for many advanced XOR problems.