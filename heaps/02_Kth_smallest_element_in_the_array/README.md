# Kth Smallest Element in an Array

## Problem Statement

Given an array `nums` and an integer `k`, find the **kth smallest element** in the array.

### Examples

```text
Input: nums = [3,2,1,5,6,4], k = 2
Output: 2

Input: nums = [7,10,4,3,20,15], k = 3
Output: 7
```

## Observations

- Sorting gives the kth smallest element at index `k-1`.
- We only need the `k` smallest elements.
- A **Max Heap** keeps the largest among these `k` elements at the top.
- If heap size exceeds `k`, remove the largest element.
- The top of the heap is the kth smallest element.

## Brute Force

- Sort the entire array in ascending order.
- The kth smallest element will be at index `k-1`.
- This is the simplest approach.

```cpp
int kthSmallest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[k - 1];
}
```

### Complexity

- **Time:** `O(N log N)` — sorting the entire array.
- **Space:** `O(1)` auxiliary space, ignoring the internal sorting implementation.

## Optimal Approach

- Use a **Max Heap** to maintain the `k` smallest elements.
- Insert every element into the heap.
- If the heap size becomes greater than `k`, remove the largest element.
- After processing all elements, the top of the heap is the kth smallest element.

```cpp
int kthSmallest(vector<int>& nums, int k) {
    priority_queue<int> pq;

    for(int x : nums) {
        pq.push(x);

        if(pq.size() > k) {
            pq.pop();
        }
    }

    return pq.top();
}
```

### Complexity

- **Time:** `O(N log K)` — each of the `N` elements is inserted into a heap of size at most `K`.
- **Space:** `O(K)` — the heap stores at most `K` elements.

## Key Takeaways

- **Kth Smallest → Max Heap**
- **Kth Largest → Min Heap**
- Maintain only `K` relevant elements instead of sorting the entire array.
- Use this pattern when finding the kth largest/smallest element.
- **Quickselect** can achieve `O(N)` average time, but it can be learned later.