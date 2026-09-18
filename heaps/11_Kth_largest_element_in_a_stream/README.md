# Kth Largest Element in a Stream

## Problem Statement

Design a class that receives numbers from a stream and returns the `kth` largest element after every new number is added.

### Examples

```text
Input:
k = 3
nums = [4,5,8,2]

add(3)  → 4
add(5)  → 5
add(10) → 5
add(9)  → 8
add(4)  → 8
```

```text
Input:
k = 4
nums = [7,7,7,7,8,3]

add(2)  → 7
add(10) → 7
add(9)  → 7
add(9) → 8
```

## Observations

- We only need the **K largest elements**, not all elements.
- Use a **min heap of size K**.
- The heap contains the K largest elements seen so far.
- `pq.top()` is the smallest among those K elements.
- Therefore, `pq.top()` is the **Kth largest element**.
- If heap size becomes `K + 1`, remove the smallest element.

## Brute Force

- Store all numbers in a vector.
- After every `add()`, sort the entire vector.
- Return the element at index `size - k`.
- Repeating the sorting makes this inefficient.

### Complexity

- **Time per `add`:** `O(N log N)`
- **Space:** `O(N)`

## Optimal Approach

- Maintain a **min heap of size K**.
- Insert every number into the heap.
- If heap size exceeds `K`, remove the smallest element.
- Thus, only the K largest elements remain in the heap.
- The smallest among them, `pq.top()`, is the Kth largest.

```cpp
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int limit;

    KthLargest(int k, vector<int>& nums) {
        limit = k;

        for(int x : nums) {
            pq.push(x);

            if(pq.size() > limit)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > limit)
            pq.pop();

        return pq.top();
    }
};
```

### Complexity

Let `N` = number of elements currently in the stream.

- Heap size is always at most `K`.
- Each insertion costs `O(log K)`.
- At most one removal costs `O(log K)`.

```text
Construction:
O(N log K)

Each add:
O(log K) + O(log K)
= O(2 log K)
= O(log K)
```

- **Space:** `O(K)`

## Key Takeaways

- **Pattern:** Kth Largest → **Min Heap of Size K**.
- Keep only the **K largest elements**.
- `pq.top()` = smallest among the K largest = **Kth largest**.
- If you need **K largest → Min Heap of K**.
- If you need **K smallest → Max Heap of K**.