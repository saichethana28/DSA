# Minimum Cost to Connect Ropes

## Problem Statement

Given an array of rope lengths, connect all ropes into one rope.

The cost of connecting two ropes is equal to their sum.

Find the minimum total cost.

### Examples

```text
Input: arr = [4,3,2,6]
Output: 29

2 + 3 = 5
4 + 5 = 9
6 + 9 = 15

Total = 5 + 9 + 15 = 29
```

```text
Input: arr = [1,2,3,4,5]
Output: 33
```

## Observations

- To minimize cost, always connect the **two smallest ropes**.
- The newly combined rope must be added back because it may be connected again.
- Repeat until only one rope remains.
- This is a **Greedy + Min Heap** problem.
- The same approach is used in **Minimum Cost to Connect Sticks**.

## Brute Force

- Find the two smallest ropes by scanning the array.
- Add their sum to the cost.
- Remove both ropes and insert the combined rope.
- Repeat until one rope remains.
- Finding the two smallest ropes repeatedly takes `O(N²)`.

### Complexity

- **Time:** `O(N²)`
- **Space:** `O(N)`

## Better Approach

- Sort the ropes first.
- Pick the two smallest ropes.
- Insert their sum back while maintaining sorted order.
- Repeat until one rope remains.
- Repeated insertion can still take `O(N²)`.

### Complexity

- **Time:** `O(N²)`
- **Space:** `O(N)`

## Optimal Approach

- Use a **min heap** so the two smallest ropes are always available at the top.
- Remove the two smallest ropes.
- Connect them and add their sum to the total cost.
- Push the combined rope back into the heap.
- Continue until only one rope remains.

```cpp
class Solution {
public:
    int minCost(vector<int>& arr) {
        int n = arr.size();

        if(n < 2)
            return 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int x : arr)
            pq.push(x);

        int cost = 0;

        while(pq.size() > 1) {
            int rope1 = pq.top();
            pq.pop();

            int rope2 = pq.top();
            pq.pop();

            int combined = rope1 + rope2;

            cost += combined;

            pq.push(combined);
        }

        return cost;
    }
};
```

### Complexity

- Building heap: `O(N log N)`
- There are `N - 1` merging operations.
- Each merge performs heap operations costing `O(log N)`.

```text
TC = O(N log N) + O((N-1) log N)
   = O(2N log N - log N)
   = O(N log N)
```

- **Space:** `O(N)`

## Key Takeaways

- **Pattern:** Greedy + Min Heap.
- Always combine the **two smallest elements**.
- Push the combined value back into the heap.
- Continue until only one element remains.
- **Minimum Cost to Connect Ropes = Minimum Cost to Connect Sticks**.