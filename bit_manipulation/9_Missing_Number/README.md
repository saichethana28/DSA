# Missing Number

## Problem Statement

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

### Example 1

**Input**
```
nums = [3,0,1]
```

**Output**
```
2
```

**Explanation**

The numbers from `0` to `3` are:

```
0 1 2 3
```

The number `2` is missing.

---

### Example 2

**Input**
```
nums = [0,1]
```

**Output**
```
2
```

---

# Brute Force Approach

## Approach

For every number from `0` to `n`:

- Traverse the entire array.
- If the number is not found, return it.

## Code

```cpp
int missingNumber(vector<int>& nums) {
    int n = nums.size();

    for(int i = 0; i <= n; i++) {
        bool found = false;

        for(int num : nums) {
            if(num == i) {
                found = true;
                break;
            }
        }

        if(!found)
            return i;
    }

    return -1;
}
```

## Complexity Analysis

- **Time Complexity:** `O(N²)`
- **Space Complexity:** `O(1)`

---

# Optimal Approach

## Key Observation

The XOR operation has two important properties:

```
x ^ x = 0

x ^ 0 = x
```

If we XOR all numbers from `0` to `n` and XOR all array elements,

every number appearing in both groups cancels out.

Only the missing number remains.

Example:

```
nums = [3,0,1]

Numbers from 0 to 3

0 ^ 1 ^ 2 ^ 3

^

3 ^ 0 ^ 1

↓

2
```

## Approach

- Compute the XOR of all numbers from `0` to `n`.
- Compute the XOR of all elements in the array.
- XOR both results.
- The remaining value is the missing number.

## Code

```cpp
int missingNumber(vector<int>& nums) {
    int n = nums.size();

    int xorNums = 0;
    int xorRange = 0;

    for(int num : nums)
        xorNums ^= num;

    for(int i = 0; i <= n; i++)
        xorRange ^= i;

    return xorNums ^ xorRange;
}
```

### More Optimized Code

```cpp
int missingNumber(vector<int>& nums) {
    int ans = nums.size();

    for(int i = 0; i < nums.size(); i++) {
        ans ^= i;
        ans ^= nums[i];
    }

    return ans;
}
```

## Complexity Analysis

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(1)`

---

# Interview Notes

- This is one of the most common XOR interview questions.
- Remember these XOR properties:

```
x ^ x = 0

x ^ 0 = x
```

- Another common solution uses the sum formula:

```
n × (n + 1) / 2
```

However, the XOR approach avoids integer overflow and demonstrates strong bit manipulation skills.

---

# What I Learned ⭐

- XOR cancels identical numbers.
- XOR can be used to find the missing element without extra space.
- Instead of storing frequencies, bit manipulation can solve the problem in linear time.
- Whenever every element appears exactly once except one missing element, XOR is often a good technique to consider.