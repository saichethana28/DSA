# Maximum Consecutive Ones III

## Problem Statement

Given a binary array `nums` and an integer `k`, return the maximum number of consecutive `1`s in the array if you can flip at most `k` zeros.

### Example

```text
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
```

## Brute Force

- Generate all subarrays.
- Count the number of `0`s in each subarray.
- If the number of zeros is `<= k`, update the maximum length.

### Complexity

- **Time:** `O(N²)`
- **Space:** `O(1)`

## Better Approach

- Use **Sliding Window** with two pointers `l` and `r`.
- Expand the window using `r`.
- Keep track of the number of zeros.
- If zeros exceed `k`, shrink the window using `while` until it becomes valid.
- Update the maximum length.

```cpp
while(zeroes > k) {
    if(nums[l] == 0) {
        zeroes--;
    }
    l++;
}

maxlen = max(maxlen, r - l + 1);
```

### Complexity

- **Time:** `O(N)`
- **Space:** `O(1)`

## Optimal Approach

- Same Sliding Window idea, but since we only need the **maximum length**, we don't need to shrink until the window becomes fully valid.
- If zeros exceed `k`, shrink **only once**.
- This keeps the window length from unnecessarily decreasing.

```cpp
if(zeroes > k) {
    if(nums[l] == 0) {
        zeroes--;
    }
    l++;
}

maxlen = max(maxlen, r - l + 1);
```

### Complexity

- **Time:** `O(N)`
- **Space:** `O(1)`

## Key Takeaways

- `zeroes` = number of zeros inside the current window.
- `zeroes > k` → window is invalid.
- **Better:** shrink using `while` until valid.
- **Optimal:** shrink only once because we only care about the longest length.