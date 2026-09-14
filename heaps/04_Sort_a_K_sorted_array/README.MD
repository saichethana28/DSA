# Sort a K-Sorted Array

## Problem Statement

Given a **k-sorted (nearly sorted)** array where every element is at most `k` positions away from its correct position, sort the array.

### Examples

```text
Input: arr = [6,5,3,2,8,10,9], k = 3
Output: [2,3,5,6,8,9,10]

Input: arr = [3,1,2], k = 2
Output: [1,2,3]
```

## Observations

- Every element is at most `k` positions away from its sorted position.
- Therefore, the next smallest element must be within the next `k+1` elements.
- A **Min Heap** can efficiently find the smallest element among these elements.
- Maintain a heap containing at most `k+1` elements.
- Place the minimum element into the next position of the array.

## Approach

- Create a **Min Heap**.
- Traverse the array and insert each element into the heap.
- When heap size becomes greater than `k`, remove the minimum and place it at the next index.
- After processing the array, remove all remaining elements from the heap.
- Since the array is k-sorted, the minimum of every `k+1` elements is the next correct element.

```cpp
void nearlySorted(vector<int>& arr, int k) {
    int idx = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);

        if(pq.size() > k) {
            arr[idx] = pq.top();
            pq.pop();
            idx++;
        }
    }

    while(!pq.empty()) {
        arr[idx] = pq.top();
        pq.pop();
        idx++;
    }
}
```

### Complexity

- **Time:** `O(N log K)` — `N` elements are inserted into a heap of size at most `K+1`, and elements are removed from the heap.
- **Space:** `O(K)` — the heap stores at most `K+1` elements.

## Key Takeaways

- **K-Sorted Array → Min Heap**
- Maintain a heap of **`K+1` elements**.
- The minimum element in the heap is the next element in sorted order.
- Useful when every element is at most `K` positions away from its correct position.
- Heap sorting reduces the work from `O(N log N)` to `O(N log K)`.