# Asteroid Collision

## Problem Statement

Given an array of integers `asteroids`, where the absolute value represents the size and the sign represents the direction:

- Positive → moving right
- Negative → moving left

When two asteroids meet, the smaller one explodes. If they are equal in size, both explode. Asteroids moving in the same direction never collide.

Return the state of the asteroids after all collisions.

### Example

Input: `asteroids = [10, 20, -10]`

Output: `[10, 20]`

Explanation: `20` and `-10` collide, but `20` survives.

---

## Approach — Stack

### Algorithm

1. Use a stack to maintain the surviving asteroids.
2. Positive asteroids are directly pushed into the stack.
3. For a negative asteroid, collisions are possible only with a positive asteroid at the stack top.
4. While the top positive asteroid is smaller, pop it.
5. If both asteroids have equal size, pop the stack and destroy the current asteroid.
6. If the stack is empty or the top asteroid is negative, push the current asteroid.
7. Convert the stack into the final answer.

### Important Condition

A collision can happen only when:

`stack.top() > 0 && current asteroid < 0`

### Code

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {

            if(asteroids[i] > 0) {
                st.push(asteroids[i]);
            }
            else {
                while(!st.empty() &&
                      st.top() > 0 &&
                      st.top() < abs(asteroids[i])) {
                    st.pop();
                }

                if(!st.empty() &&
                   st.top() == abs(asteroids[i])) {
                    st.pop();
                }
                else if(st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                }
            }
        }

        int s = st.size();
        vector<int> ans(s);

        s--;

        while(!st.empty()) {
            ans[s] = st.top();
            st.pop();
            s--;
        }

        return ans;
    }
};

## Complexity

- Time: `O(N)`
- Space: `O(N)`

## Key Takeaways

- Use a stack to maintain surviving asteroids.
- Only `positive → negative` pairs can collide.
- Smaller asteroid is popped.
- Equal-sized asteroids destroy each other.
- A larger asteroid survives and may continue colliding with previous asteroids.
- Always check `!st.empty()` before using `st.top()`.