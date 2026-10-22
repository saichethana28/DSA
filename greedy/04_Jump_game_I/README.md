# Jump Game

## Problem Statement

Given an array where `nums[i]` represents the maximum jump length from index `i`, determine whether you can reach the last index from index `0`.

### Examples

```text
nums = [2,3,1,1,4]
Output: true
```

```text
nums = [3,2,1,0,4]
Output: false
```

## Observations

- `maxReach` stores the farthest index reachable so far.
- From index `i`, the farthest possible position is `i + nums[i]`.
- If `i > maxReach`, the current index is unreachable.
- If the loop finishes, the last index is reachable.
- Equality is allowed: `i == maxReach` means the current index is reachable.

## Brute Force

- Try every possible jump from the current index.
- Recursively check whether any path reaches the last index.
- Return `true` if at least one path succeeds.

### Complexity

- **Time:** `O(2^N)` worst case for a straightforward recursive solution.
- **Space:** `O(N)` recursion stack.

## Optimal Approach

- Initialise `maxReach = 0`.
- Traverse the array from left to right.
- If `i > maxReach`, return `false`.
- Otherwise, update `maxReach = max(maxReach, i + nums[i])`.
- If traversal completes, return `true`.

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(i > maxReach) {
                return false;
            }

            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};
```

### Complexity

- **Time:** `O(N)` — one traversal.
- **Space:** `O(1)` — only one variable.

## Key Takeaways

- **Pattern:** Greedy / Farthest Reach.
- Track the farthest index reachable so far.
- Check reachability **before** updating `maxReach`.
- Use `i > maxReach`, not `i >= maxReach`.
- Reaching the last index is enough; you do not need to jump beyond it.