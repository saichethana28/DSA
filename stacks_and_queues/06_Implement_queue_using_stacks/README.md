# 232. Implement Queue using Stacks

## Problem Statement

Implement a **Queue** using only **Stack** operations.

The queue should support the following operations:

- `push(x)` → Insert an element at the back of the queue.
- `pop()` → Remove and return the front element.
- `peek()` → Return the front element.
- `empty()` → Return `true` if the queue is empty, otherwise `false`.

**Note:** Only standard stack operations are allowed:
- Push to top
- Pop from top
- Peek top
- Size
- Empty

### Example

**Input**
```
push(1)
push(2)
peek()
pop()
empty()
```

**Output**
```
1
1
false
```

---

# Better Approach (Using Two Stacks - Costly Push)

## Key Observation

A queue follows **FIFO**, whereas a stack follows **LIFO**.

To maintain queue order, we rearrange the elements **during every push**.

Whenever a new element is pushed:

1. Move all elements from `st1` to `st2`.
2. Push the new element into `st1`.
3. Move all elements back from `st2` to `st1`.

This ensures the **front element always remains on top of `st1`**.

### Example

Initially

```
st1

Top
1
2
3
```

Push `4`

Move everything to `st2`

```
st2

Top
3
2
1
```

Push `4`

```
st1

Top
4
```

Move back

```
st1

Top
1
2
3
4
```

Now the front of the queue is always at the top of `st1`.

## Approach

- Maintain two stacks.
- During every push:
  - Move all elements to the second stack.
  - Insert the new element.
  - Move all elements back.
- `pop()` simply pops from `st1`.
- `peek()` returns `st1.top()`.

## Code

```cpp
class MyQueue {
public:
    stack<int> st1, st2;

    void push(int x) {

        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(x);

        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop() {

        int x = st1.top();
        st1.pop();
        return x;
    }

    int peek() {
        return st1.top();
    }

    bool empty() {
        return st1.empty();
    }
};
```

## Complexity Analysis

| Operation | Time Complexity |
|-----------|-----------------|
| Push | `O(N)` |
| Pop | `O(1)` |
| Peek | `O(1)` |
| Empty | `O(1)` |

**Space Complexity:** `O(N)`

---

# Optimal Approach (Using Two Stacks - Amortized O(1))

## Key Observation

Instead of rearranging elements during every push, we delay the transfer until it is actually needed.

Maintain two stacks:

- `st1` → Used for all incoming elements.
- `st2` → Used for removing elements.

Whenever `pop()` or `peek()` is called:

- If `st2` is empty, move all elements from `st1` to `st2`.
- Otherwise, directly use `st2`.

Each element is transferred **at most once** from `st1` to `st2`, giving an **amortized O(1)** complexity.

### Example

Initially

```
st1

Top
2
1

st2

Empty
```

Call `pop()`

Transfer all elements

```
st2

Top
1
2
```

Now

```
pop()

returns 1
```

Next pop

```
returns 2
```

No transfer is required until `st2` becomes empty again.

## Approach

- Push every new element into `st1`.
- During `pop()` or `peek()`:
  - If `st2` is empty, transfer all elements from `st1` to `st2`.
  - Perform the required operation on `st2`.
- `empty()` returns whether both stacks are empty.

## Code

```cpp
class MyQueue {
public:
    stack<int> st1, st2;

    MyQueue() {
    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {

        if(st2.empty()) {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        int res = st2.top();
        st2.pop();

        return res;
    }

    int peek() {

        if(st2.empty()) {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};
```

## Complexity Analysis

| Operation | Time Complexity |
|-----------|-----------------|
| Push | `O(1)` |
| Pop | `O(1)` (Amortized) |
| Peek | `O(1)` (Amortized) |
| Empty | `O(1)` |

**Space Complexity:** `O(N)`

---

# Interview Notes

- Queue follows **FIFO**, while Stack follows **LIFO**.
- The first approach makes **push()** costly so that `pop()` and `peek()` become constant time.
- The optimal approach delays the transfer until necessary.
- Every element moves from `st1` to `st2` at most once, giving **amortized O(1)** complexity.
- This is the follow-up expected in interviews and is the preferred implementation.

---

# What I Learned ⭐

- A queue can be implemented using two stacks by reversing the order of elements.
- There is a trade-off between making `push()` expensive and making `pop()` expensive.
- Lazy transfer between two stacks results in an amortized `O(1)` solution.
- Understanding **amortized analysis** is important, as an operation may occasionally take `O(N)`, but the average cost over many operations remains constant.