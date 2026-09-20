# Choose K Elements With Maximum Sum

## Problem Statement

For every index `i`, choose at most `k` values from `nums2[j]` where `nums1[j] < nums1[i]` and maximize their sum.

### Examples

```text
nums1 = [4,2,1,5,3]
nums2 = [10,20,30,40,50]
k = 2

Output = [80,30,0,80,50]
```

```text
nums1 = [2,2,2,2]
nums2 = [3,1,2,3]
k = 1

Output = [0,0,0,0]
```

## Observations

- Sort indices by `nums1`.
- Maintain the largest `k` values of `nums2` using a **min heap**.
- `sum` stores the sum of the current `k` largest values.
- For equal `nums1` values, calculate all their answers **before** inserting their `nums2`.
- This is necessary because the condition is strictly `nums1[j] < nums1[i]`.

## Brute Force

- For every `i`, scan all `j` and collect valid `nums2[j]`.
- Use a min heap of size `k` to keep the largest `k` values.
- Calculate their sum independently for every `i`.

```cpp
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> ans;

        for(int i = 0; i < n; i++) {
            priority_queue<int, vector<int>, greater<int>> pq;

            for(int j = 0; j < n; j++) {
                if(nums1[j] < nums1[i]) {
                    pq.push(nums2[j]);

                    if(pq.size() > k)
                        pq.pop();
                }
            }

            long long sum = 0;

            while(!pq.empty()) {
                sum += pq.top();
                pq.pop();
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
```

### Complexity

- For every `i`: `O(N + N log K + K)`
- **Total:** `O(N² + N² log K + NK)`
- **Space:** `O(N + K)`

## Optimal Approach

- Store `(nums1[i], i)` and sort by `nums1`.
- Process equal `nums1` values as one group.
- First assign the current `sum` to every index in the group.
- Then insert their `nums2` values into the min heap.
- If heap size exceeds `k`, remove the smallest value.

```cpp
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++)
            v.push_back({nums1[i], i});

        sort(v.begin(), v.end());

        vector<long long> ans(n);

        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0;
        int i = 0;

        while(i < n) {
            int j = i;

            while(j < n && v[j].first == v[i].first)
                j++;

            // Equal nums1 values must get the same answer
            for(int x = i; x < j; x++)
                ans[v[x].second] = sum;

            // Add this group for future larger nums1 values
            for(int x = i; x < j; x++) {
                int idx = v[x].second;

                pq.push(nums2[idx]);
                sum += nums2[idx];

                if(pq.size() > k) {
                    sum -= pq.top();
                    pq.pop();
                }
            }

            i = j;
        }

        return ans;
    }
};
```

### Complexity

- Sorting: `O(N log N)`
- Heap operations: `O(N log K)`
- **Total:** `O(N log N + N log K)` → `O(N log N)`
- **Space:** `O(N + K)` → `O(N)`

## Key Takeaways

- **Pattern:** Sorting + Min Heap of Size `K`.
- **K largest elements → Min Heap of size K.**
- Maintain `sum` so we don't repeatedly calculate the top `K`.
- With a strict `<` condition, **equal values must be processed as a group**.
- Pattern: **Answer group → Add group → Move to next group**.