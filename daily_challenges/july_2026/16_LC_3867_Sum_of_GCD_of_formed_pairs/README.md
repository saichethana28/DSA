# LC 3867 - Sum of GCD of Formed Pairs

## Problem

Given an array `nums`:

1. Construct `prefixGcd` where:
   - `mxi` = maximum element from `nums[0...i]`
   - `prefixGcd[i] = gcd(nums[i], mxi)`
2. Sort `prefixGcd`.
3. Pair the smallest and largest remaining elements.
4. Sum the GCD of every pair.
5. If the array size is odd, ignore the middle element.

Return the final sum.

---

# Brute Force Approach

## Idea

Construct the `prefixGcd` array, sort it, then repeatedly pair the smallest and largest elements while computing their GCD.

### Algorithm

1. Compute the prefix maximum for every index.
2. Compute `prefixGcd[i] = gcd(nums[i], prefixMax[i])`.
3. Sort the `prefixGcd` array.
4. Use two pointers:
   - Left → Smallest element
   - Right → Largest element
5. Add `gcd(prefixGcd[left], prefixGcd[right])` to the answer.
6. Continue until all possible pairs are processed.

### Complexity

- **Time Complexity:** `O(N log N)`
- **Space Complexity:** `O(N)`

### Code

```cpp
class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefixMax;
        vector<int> prefixGcd;

        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefixMax.push_back(maxi);
        }

        for (int i = 0; i < n; i++) {
            prefixGcd.push_back(gcd(nums[i], prefixMax[i]));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;

        int left = 0;
        int right = n - 1;

        while (left < right) {

            sum += gcd(prefixGcd[left], prefixGcd[right]);

            left++;
            right--;
        }

        return sum;
    }
};
```

---

# Optimal Approach

## Key Observation

- The prefix maximum can be computed in a single traversal.
- Each `prefixGcd` value depends only on the current element and the prefix maximum.
- Sorting allows pairing the smallest and largest elements efficiently using two pointers.
- Every element is paired exactly once, so a two-pointer approach is sufficient after sorting.

### Algorithm

1. Traverse the array and compute the prefix maximum.
2. Construct the `prefixGcd` array.
3. Sort `prefixGcd`.
4. Pair elements from both ends using two pointers.
5. Compute the GCD of each pair and add it to the answer.

### Complexity

- **Time Complexity:** `O(N log N)`
  - Prefix computation → `O(N)`
  - Sorting → `O(N log N)`
  - Pairing → `O(N)`
- **Space Complexity:** `O(N)`

### Code

```cpp
class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefixMax;
        vector<int> prefixGcd;

        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefixMax.push_back(maxi);
        }

        for (int i = 0; i < n; i++) {
            prefixGcd.push_back(gcd(nums[i], prefixMax[i]));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;

        int left = 0;
        int right = n - 1;

        while (left < right) {

            sum += gcd(prefixGcd[left], prefixGcd[right]);

            left++;
            right--;
        }

        return sum;
    }
};
```

---

# Interview Discussion

- Prefix maximum can be computed in a single pass.
- Sorting naturally enables pairing the smallest and largest elements using two pointers.
- The overall complexity is dominated by sorting (`O(N log N)`).

---

# What I Learned ⭐

- Prefix arrays are useful for storing cumulative information efficiently.
- `std::gcd()` (or `__gcd()`) can be used directly for GCD calculations.
- Sorting followed by the two-pointer technique is a common pairing strategy.
- Break problems into independent phases (prefix computation, transformation, sorting, pairing) to simplify the implementation.