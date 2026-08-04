# Single Number II

## Problem Statement

Given an integer array `nums`, every element appears **exactly three times** except for **one element**, which appears only once.

Find and return that unique element.

You must solve the problem in **linear time** and with **constant extra space**.

### Example 1

**Input**
```
nums = [2,2,3,2]
```

**Output**
```
3
```

**Explanation**

```
2 appears three times.
3 appears only once.
```

Hence, the answer is `3`.

---

### Example 2

**Input**
```
nums = [0,1,0,1,0,1,99]
```

**Output**
```
99
```

---

# Brute Force Approach

## Approach

For every element:

- Count its frequency by traversing the entire array.
- If its frequency is `1`, return that element.

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

Every element except one appears **three times**.

Instead of counting the frequency of each number, count the number of **set bits at every bit position**.

For each bit position:

- If the count of set bits is divisible by `3`, those bits belong entirely to numbers appearing three times.
- If the count is **not divisible by 3**, then the unique number has that bit set.

Example:

```
nums = [2,2,3,2]

Binary Representation

2 -> 0010
2 -> 0010
3 -> 0011
2 -> 0010

Bit Count

Bit 0 -> 1
Bit 1 -> 4
Bit 2 -> 0
Bit 3 -> 0

Taking modulo 3

1 % 3 = 1
4 % 3 = 1
0 % 3 = 0
0 % 3 = 0

Result

0011 = 3
```

## Approach

- Traverse all 32 bit positions.
- Count how many numbers have that bit set.
- If the count is not divisible by `3`, set that bit in the answer.
- Return the reconstructed number.

## Code

```cpp
int singleNumber(vector<int>& nums) {
    int ans = 0;

    for(int i = 0; i < 32; i++) {
        int count = 0;

        for(int num : nums) {
            if(num & (1 << i))
                count++;
        }

        if(count % 3)
            ans |= (1 << i);
    }

    return ans;
}
```

## Complexity Analysis

- **Time Complexity:** `O(32 × N)` ≈ `O(N)`
- **Space Complexity:** `O(1)`

---

# Interview Notes

- This is one of the most popular bit manipulation interview questions.
- The XOR trick used in **Single Number I** does **not** work here because elements appear **three times** instead of twice.
- Counting set bits at every position is the key idea.
- The same technique can be generalized when every element appears **k times** except one.

---

# What I Learned ⭐

- Frequency counting can be performed on **individual bit positions** instead of whole numbers.
- Taking modulo `3` removes the contribution of numbers appearing three times.
- The remaining set bits reconstruct the unique number.
- Bit counting is a powerful technique that extends beyond simple XOR problems.