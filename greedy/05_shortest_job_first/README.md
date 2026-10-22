# Shortest Job First

## Problem Statement

Given an array `bt[]` representing the burst times of `N` processes, schedule the shortest process first and return the floor of the average waiting time. All processes arrive at time `0`.

### Examples

```text
Input: bt = [4,3,7,1,2]
Output: 4
```

```text
Input: bt = [1,2,3,4]
Output: 2
```

## Observations

- **Burst time** is the CPU time required to complete a process.
- Sort burst times in ascending order to minimise waiting time.
- The first process has waiting time `0`.
- Each subsequent process waits for the sum of all previous burst times.
- Return `total waiting time / N`, using integer division to get the floor.

## Brute Force

- Try different execution orders of the processes.
- Calculate the average waiting time for each order.
- Return the minimum average.
- This is inefficient because many possible orderings exist.

### Complexity

- **Time:** `O(N! × N)` — checking all permutations and calculating waiting times.
- **Space:** `O(N)` — storing an execution order.

## Optimal Approach

- Sort burst times in ascending order.
- Maintain `sum` as the cumulative burst time of previous processes.
- Add `sum` to `total` to calculate each waiting time.
- Stop at `N - 1`, because the last process's burst time does not contribute to any subsequent waiting time.
- Divide `total` by `N` using integer division.

```cpp
class Solution {
public:
    int solve(vector<int>& bt) {
        int n = bt.size();

        sort(bt.begin(), bt.end());

        long long total = 0;
        long long sum = 0;

        for(int i = 0; i < n - 1; i++) {
            sum += bt[i];
            total += sum;
        }

        return total / n;
    }
};
```

### Complexity

- **Time:** `O(N log N)` — sorting dominates.
- **Space:** `O(1)` auxiliary space, excluding sorting implementation details.

## Key Takeaways

- **Pattern:** Greedy + Sorting.
- Always execute the shortest process first.
- Waiting time = sum of all previous burst times.
- Maintain a cumulative sum instead of recalculating waiting times.
- Use integer division to return the floor of the average.