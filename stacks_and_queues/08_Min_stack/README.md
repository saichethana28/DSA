# 155. Min Stack

## Problem Statement

Design a stack that supports the following operations in **O(1)** time:

- `push(val)`
- `pop()`
- `top()`
- `getMin()`

---

## Example

### Example 1

**Input**
```text
["MinStack","push","push","push","getMin","pop","top","getMin"]

[[],[-2],[0],[-3],[],[],[],[]]
```

**Output**
```text
[null,null,null,null,-3,null,0,-2]
```

**Explanation**

```text
push(-2)
push(0)
push(-3)

Stack:
Top
-3
 0
-2

Minimum = -3

pop()

Stack:
Top
0
-2

Minimum = -2
```

---

## Understanding the Problem

- A normal stack supports `push`, `pop`, and `top` in **O(1)** time.
- We additionally need to return the minimum element in **O(1)**.
- Traversing the stack every time is too slow.
- We need a way to maintain the minimum while performing stack operations.

---

# Approach 1 : Stack of Pairs (O(2N) Space)

### Idea

- Maintain a stack of pairs `{value, minimum_so_far}`.
- For every push, compute the minimum till that point.
- Store both the current value and current minimum.
- The top pair always contains the minimum of the entire stack.
- `getMin()` simply returns the second value of the top pair.

## Code

```cpp
class MinStack {
public:
    stack<pair<int,int>> st;

    MinStack() {
    }

    void push(int value) {

        if(st.empty()) {
            st.push({value, value});
        }
        else {
            int mini = min(value, st.top().second);
            st.push({value, mini});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};
```

### Complexity Analysis

**Time Complexity:** `O(1)` for all operations

**Space Complexity:** `O(2N)` (Each stack element stores two integers.)

---

# Approach 2 : Single Stack + Encoding Technique (O(N) Space)

### Idea

- Maintain only one stack and a variable `mini`.
- Push normal values if they are greater than or equal to the current minimum.
- If a new minimum arrives, push an encoded value `2*val - mini`.
- Update the current minimum.
- During pop, if the encoded value is encountered, recover the previous minimum.
- Thus, only one integer is stored per stack element.

## Code

```cpp
class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
    }

    void push(int value) {

        if(st.empty()) {
            mini = value;
            st.push(value);
        }
        else if(value >= mini) {
            st.push(value);
        }
        else {
            st.push(2LL * value - mini);
            mini = value;
        }
    }

    void pop() {

        if(st.empty()) return;

        long long x = st.top();
        st.pop();

        if(x < mini) {
            mini = 2LL * mini - x;
        }
    }

    int top() {

        long long x = st.top();

        if(x >= mini)
            return x;

        return mini;
    }

    int getMin() {
        return mini;
    }
};
```

### Complexity Analysis

**Time Complexity:** `O(1)` for all operations

**Space Complexity:** `O(N)`

---

# Key Takeaways ⭐

- A normal stack cannot return the minimum in constant time without extra information.
- Storing `{value, minimum_so_far}` is the easiest and most intuitive solution.
- The encoding technique reduces the auxiliary space from **O(2N)** to **O(N)** while maintaining **O(1)** operations.
- This is one of the most popular stack design problems asked in product-based company interviews.
- The encoding approach is an excellent interview follow-up and demonstrates a deeper understanding of data structure optimization.