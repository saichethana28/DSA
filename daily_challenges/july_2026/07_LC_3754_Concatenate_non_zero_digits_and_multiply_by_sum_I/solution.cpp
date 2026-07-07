```cpp
/*
LeetCode 3754 - Concatenate Non-Zero Digits and Multiply by Sum I

Approach:
1. Traverse the digits from right to left.
2. Ignore zero digits.
3. Build the new number using a multiplier (1, 10, 100, ...).
4. Simultaneously compute the sum of the non-zero digits.
5. Return number × sum.

Time Complexity : O(d)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        long long sum = 0;
        long long multiplier = 1;

        while (n != 0) {
            int rem = n % 10;

            if (rem != 0) {
                num += multiplier * rem;
                sum += rem;
                multiplier *= 10;
            }

            n /= 10;
        }

        return num * sum;
    }
};
```
