# Kth Largest Element in an Array

## Problem Statement

Given an array `nums` and an integer `k`, find the **kth largest element** in the array.

### Examples

```text
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Input: nums = [7,10,4,3,20,15], k = 3
Output: 10
```

## Observations

- Sorting gives the kth largest element at index `N-k`.
- We only need the `k` largest elements.
- A **Min Heap** keeps the smallest among these `k` elements at the top.
- If heap size exceeds `k`, remove the smallest element.
- The top of the heap is the kth largest element.

## Brute Force

- Sort the entire array in ascending order.
- The kth largest element will be at index `N-k`.
- This is the simplest approach.

```cpp
int kthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return nums[n - k];
}
```

### Complexity

- **Time:** `O(N log N)` — sorting the entire array.
- **Space:** `O(1)` auxiliary space, ignoring the internal sorting implementation.

## Optimal Approach

- Use a **Min Heap** to maintain the `k` largest elements.
- Insert every element into the heap.
- If the heap size becomes greater than `k`, remove the smallest element.
- After processing all elements, the top of the heap is the kth largest element.

```cpp
int kthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

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

- **Kth Largest → Min Heap**
- **Kth Smallest → Max Heap**
- Maintain only `K` relevant elements instead of sorting the entire array.
- Use this pattern when finding the kth largest/smallest element.
- **Quickselect** can achieve `O(N)` average time, but it can be learned later.