# Implement Stack using Array

## Problem Statement

Implement a **Stack** using an array of fixed size `n`.

The stack should support the following operations:

- `push(x)` → Insert an element at the top of the stack.
- `pop()` → Remove the top element from the stack.
- `peek()` → Return the top element of the stack. If the stack is empty, return `-1`.
- `isEmpty()` → Return `true` if the stack is empty, otherwise `false`.
- `isFull()` → Return `true` if the stack is full, otherwise `false`.

---

### Example 1

**Input**
```
Capacity = 3

push(5)
push(3)
peek()
pop()
isEmpty()
isFull()
```

**Output**
```
3
false
false
```

**Explanation**

```
Initially

[]

push(5)

[5]

push(3)

[5, 3]

peek()

Top = 3

pop()

[5]

isEmpty() = false

isFull() = false
```

---

### Example 2

**Input**
```
Capacity = 1

pop()
peek()
isEmpty()
push(9)
isFull()
```

**Output**
```
-1
true
true
```

---

# Brute Force Approach

## Approach

Use a dynamic array (`vector`) and perform operations using built-in functions.

- `push_back()` to insert.
- `pop_back()` to remove.
- `back()` to access the top element.

Although simple, this approach relies on STL rather than implementing the stack manually.

## Code

```cpp
class myStack {
private:
    int size;
    vector<int> st;

public:
    myStack(int n) {
        size = n;
    }

    bool isEmpty() {
        return st.empty();
    }

    bool isFull() {
        return st.size() == size;
    }

    void push(int x) {
        if(!isFull())
            st.push_back(x);
    }

    void pop() {
        if(!isEmpty())
            st.pop_back();
    }

    int peek() {
        if(isEmpty())
            return -1;
        return st.back();
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(1)` for all operations
- **Space Complexity:** `O(N)`

---

# Optimal Approach

## Key Observation

A stack follows the **LIFO (Last In, First Out)** principle.

We only need to keep track of the **top** element.

Initially,

```
top = -1
```

Whenever an element is pushed,

```
top++
```

Whenever an element is popped,

```
top--
```

The array stores all elements, while `top` always points to the current top of the stack.

Example:

```
Capacity = 5
```

Initially

```
Index

0 1 2 3 4

Top = -1
```

After

```
push(10)
push(20)
push(30)
```

```
Index

0   1   2   3   4
-------------------
10  20  30

Top = 2
```

After

```
pop()
```

```
Index

0   1   2
-----------
10  20

Top = 1
```

Only the value of `top` changes.

## Approach

- Maintain an array of fixed size.
- Maintain an integer `top`.
- Push:
  - Check if the stack is full.
  - Increment `top`.
  - Store the element.
- Pop:
  - Check if the stack is empty.
  - Decrement `top`.
- Peek:
  - Return `arr[top]`.
- `isEmpty()` returns whether `top == -1`.
- `isFull()` returns whether `top == size - 1`.

## Code

```cpp
class myStack {
private:
    int top;
    int size;
    vector<int> arr;

public:
    myStack(int n) {
        size = n;
        top = -1;
        arr.resize(n);
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(int x) {
        if (!isFull()) {
            arr[++top] = x;
        }
    }

    void pop() {
        if (!isEmpty()) {
            --top;
        }
    }

    int peek() {
        return isEmpty() ? -1 : arr[top];
    }
};
```

## Complexity Analysis

| Operation | Time Complexity |
|-----------|-----------------|
| Push | `O(1)` |
| Pop | `O(1)` |
| Peek | `O(1)` |
| isEmpty | `O(1)` |
| isFull | `O(1)` |

**Overall Space Complexity:** `O(N)`

---

# Interview Notes

- Stack follows the **LIFO (Last In, First Out)** principle.
- `top` always points to the last inserted element.
- Initially, `top = -1` because there are no elements.
- Overflow occurs when the stack becomes full.
- Underflow occurs when attempting to pop from an empty stack.
- Array implementation is simple and cache-friendly but has a fixed capacity.

---

# What I Learned ⭐

- A stack can be efficiently implemented using an array and a single `top` pointer.
- All stack operations can be performed in constant time.
- `top == -1` indicates an empty stack, while `top == size - 1` indicates a full stack.
- Array-based stacks are efficient but have a fixed size limitation, unlike linked-list implementations which can grow dynamically.