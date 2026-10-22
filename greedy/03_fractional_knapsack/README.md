# Fractional Knapsack

## Problem Statement

Given the value and weight of each item and a knapsack capacity, maximise the total value. You can take fractions of items.

### Examples

```text
val = [60,100,120]
wt = [10,20,30]
capacity = 50

Output: 240.0
```

```text
val = [500]
wt = [30]
capacity = 10

Output: 166.6667
```

## Observations

- Items can be divided into fractions.
- Calculate the value-to-weight ratio: `val[i] / wt[i]`.
- Choose items with the highest ratio first.
- If an item does not fit completely, take the fraction that fits.
- Use `double` to avoid integer division.

## Brute Force

- Try different combinations and fractions of items.
- Calculate the total value for each possibility.
- Choose the maximum value.

### Complexity

- No single complexity applies without specifying how the possible fractions are enumerated.

## Optimal Approach

- Store each item's ratio and original index.
- Sort items by ratio in descending order.
- Take the whole item if it fits.
- Otherwise, take the fraction that fits and stop.

```cpp
class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double,int>> p;

        for(int i = 0; i < n; i++) {
            double ratio = (double)val[i] / wt[i];
            p.push_back({ratio, i});
        }

        sort(p.rbegin(), p.rend());

        double ans = 0;

        for(int i = 0; i < n; i++) {
            int idx = p[i].second;

            if(wt[idx] <= capacity) {
                ans += val[idx];
                capacity -= wt[idx];
            } else {
                ans += p[i].first * capacity;
                break;
            }
        }

        return ans;
    }
};
```

### Complexity

- **Time:** `O(N log N)` — sorting the items.
- **Space:** `O(N)` — storing ratios and indices.

## Key Takeaways

- **Pattern:** Greedy.
- Sort by **value / weight**, not by value alone.
- Take the highest ratio first.
- Use floating-point division.
- Fractional Knapsack allows fractions; 0/1 Knapsack does not.