# 225. Implement Stack using Queues

## Problem Statement

Implement a **Stack** using only **Queue** operations.

The stack should support the following operations:

- `push(x)` → Push an element onto the stack.
- `pop()` → Remove and return the top element.
- `top()` → Return the top element.
- `empty()` → Return `true` if the stack is empty, otherwise `false`.

**Note:** Only standard queue operations are allowed:
- Push to back
- Pop from front
- Peek front
- Size
- Empty

### Example

**Input**
```
push(1)
push(2)
top()
pop()
empty()
```

**Output**
```
2
2
false
```

---

# Better Approach (Using Two Queues)

## Key Observation

A stack follows **LIFO**, whereas a queue follows **FIFO**.

To simulate stack behavior, we always maintain the **newest element at the front** of the primary queue.

Whenever a new element is pushed:

1. Push it into the second queue.
2. Move all elements from the first queue into the second queue.
3. Swap the two queues.

### Example

Initially

```
q1

1 2 3
```

Push `4`

```
q2

4
```

Move all elements from `q1` to `q2`

```
q2

4 1 2 3
```

Swap both queues

```
q1

4 1 2 3
```

Now the front of `q1` is always the stack top.

## Approach

- Maintain two queues.
- During every push:
  - Insert into the empty queue.
  - Transfer all existing elements.
  - Swap both queues.
- `pop()` removes the front element.
- `top()` returns the front element.

## Code

```cpp
class MyStack {
public:
    queue<int> q1, q2;

    void push(int x) {

        q2.push(x);

        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {

        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
```

## Complexity Analysis

| Operation | Time Complexity |
|-----------|-----------------|
| Push | `O(N)` |
| Pop | `O(1)` |
| Top | `O(1)` |
| Empty | `O(1)` |

**Space Complexity:** `O(N)`

---

# Optimal Approach (Using One Queue)

## Key Observation

Instead of maintaining two queues, we can achieve the same behavior using **only one queue**.

Whenever a new element is inserted:

1. Push it to the rear.
2. Rotate all previously existing elements to the back.

This brings the newly inserted element to the front.

### Example

Initially

```
1 2 3
```

Push `4`

```
1 2 3 4
```

Rotate

```
2 3 4 1
```

```
3 4 1 2
```

```
4 1 2 3
```

Now the newest element is always at the front.

## Approach

- Push the element into the queue.
- Rotate the first `size - 1` elements.
- The front of the queue always represents the stack top.
- `pop()` removes the front element.
- `top()` returns the front element.

## Code

```cpp
class MyStack {
public:
    queue<int> q;

    MyStack() {
    }

    void push(int x) {

        q.push(x);

        int n = q.size();

        for(int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {

        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
```

## Complexity Analysis

| Operation | Time Complexity |
|-----------|-----------------|
| Push | `O(N)` |
| Pop | `O(1)` |
| Top | `O(1)` |
| Empty | `O(1)` |

**Space Complexity:** `O(N)`

---

# Interview Notes

- Stack follows **LIFO**, whereas Queue follows **FIFO**.
- The two-queue approach is easier to understand and implement.
- The one-queue approach achieves the same result by rotating the queue after every insertion.
- Both approaches make `push()` costly while keeping `pop()` and `top()` efficient.
- Another valid design is to make `push()` **O(1)** and `pop()` **O(N)** by delaying the rearrangement until `pop()`.

---

# What I Learned ⭐

- A stack can be implemented using queue operations by rearranging the order of elements after every insertion.
- Rotating elements transforms FIFO behavior into LIFO behavior.
- The one-queue solution is a space-optimized version of the two-queue approach.
- Multiple implementations are possible depending on whether we want to optimize `push()` or `pop()`.