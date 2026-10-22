# Lemonade Change

## Problem Statement

Customers pay using ₹5, ₹10, or ₹20 bills. Each lemonade costs ₹5. Return `true` if you can provide the correct change to every customer in order; otherwise, return `false`.

### Examples

```text
Input: bills = [5,5,5,10,20]
Output: true
```

```text
Input: bills = [5,5,10,10,20]
Output: false
```

## Observations

- A ₹5 bill requires no change.
- A ₹10 bill requires one ₹5 bill as change.
- A ₹20 bill requires ₹15 as change.
- For ₹20, prefer one ₹10 + one ₹5 over three ₹5 bills.
- We only need to track the counts of ₹5 and ₹10 bills.

## Brute Force

- Try different combinations of available bills to give change.
- Track the remaining bills after each customer.
- This is unnecessary because a greedy choice is sufficient.

## Optimal Approach

- Traverse the bills from left to right.
- For ₹5, increment `fives`.
- For ₹10, use one ₹5 bill; return `false` if unavailable.
- For ₹20, prefer one ₹10 and one ₹5; otherwise use three ₹5 bills.
- If neither combination is possible, return `false`.

```cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;

        for(int bill : bills) {
            if(bill == 5) {
                fives++;
            }
            else if(bill == 10) {
                if(fives > 0) {
                    fives--;
                    tens++;
                }
                else {
                    return false;
                }
            }
            else {
                if(fives >= 1 && tens >= 1) {
                    fives--;
                    tens--;
                }
                else if(fives >= 3) {
                    fives -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};
```

### Complexity

- **Time:** `O(N)` — visit each bill once.
- **Space:** `O(1)` — only two counters.

## Key Takeaways

- **Pattern:** Greedy.
- Prefer change that preserves smaller bills for future customers.
- For ₹20, prefer ₹10 + ₹5 over three ₹5 bills.
- Return `false` immediately when exact change is impossible.
- Watch out for `=` (assignment) versus `==` (comparison).