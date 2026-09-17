# Task Scheduler

## Problem Statement

Given tasks and a cooldown `n`, execute all tasks such that the same task has at least `n` intervals between two executions. Find the minimum number of intervals, including idle time.

### Examples

```text
Input:  tasks = [A,A,A,B,B,B], n = 2
Output: 8
```

```text
Input:  tasks = [A,A,A], n = 2
Output: 7
```

## Observations

- The most frequent task creates the required spacing.
- Other tasks can fill the idle gaps.
- If multiple tasks have the maximum frequency, they can occupy the same positions in the schedule.
- If enough tasks fill all gaps, no idle time is needed.

## Brute Force

- Simulate the scheduling process using a max heap.
- Always pick the currently available task with the highest frequency.
- Put executed tasks into a cooldown queue until they become available again.
- This directly simulates the CPU timeline.

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char c : tasks)
            freq[c - 'A']++;

        priority_queue<int> pq;

        for(int x : freq)
            if(x) pq.push(x);

        queue<pair<int,int>> q;
        int time = 0;

        while(!pq.empty() || !q.empty()) {
            time++;
            int count = 0;

            if(!pq.empty()) {
                count = pq.top();
                pq.pop();
                count--;

                if(count)
                    q.push({count, time + n});
            }

            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
```

### Complexity

- **Time:** `O(T log 26)` — each task is processed with heap operations → **O(T)** since there are only 26 task types.
- **Space:** `O(26)` — heap and cooldown queue store at most 26 task types → **O(1)**.

## Optimal Approach

- Let `maxFreq` be the highest task frequency.
- These tasks create `maxFreq - 1` gaps, each requiring `n + 1` positions.
- If `countMax` tasks have the maximum frequency, they occupy the final group.
- Compare this required structure with the total number of tasks.

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char c : tasks)
            freq[c - 'A']++;

        int maxFreq = 0;

        for(int x : freq)
            maxFreq = max(maxFreq, x);

        int countMax = 0;

        for(int x : freq)
            if(x == maxFreq)
                countMax++;

        int ans = (maxFreq - 1) * (n + 1) + countMax;

        return max((int)tasks.size(), ans);
    }
};
```

### Complexity

- **Time:** `O(T) + O(26) + O(26)` — count frequencies and find `maxFreq` and `countMax` → **O(T)**.
- **Space:** `O(26)` — frequency array → **O(1)**.

## Key Takeaways

- **Most frequent task → creates the schedule skeleton.**
- `maxFreq - 1` → number of gaps.
- `n + 1` → size of each gap block.
- `countMax` → tasks in the final group.
- Final answer: `max(T, (maxFreq - 1) * (n + 1) + countMax)`.