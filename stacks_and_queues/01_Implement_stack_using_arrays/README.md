# Implement Stack using Array

## Problem Statement

Implement a **Stack** using a fixed-size array of capacity `n`.

The stack should support the following operations:

- `push(x)` → Insert an element at the top.
- `pop()` → Remove the top element.
- `peek()` → Return the top element. If the stack is empty, return `-1`.
- `isEmpty()` → Return `true` if the stack is empty, otherwise `false`.
- `isFull()` → Return `true` if the stack is full, otherwise `false`.

### Example

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

# Approach

## Key Idea

A stack follows the **LIFO (Last In, First Out)** principle.

We maintain:

- A fixed-size array to store the elements.
- A variable `top` that always points to the topmost element.

Initially,

```
top = -1
```

Operations:

- **Push**
  - Check if the stack is full.
  - Increment `top`.
  - Store the element.

- **Pop**
  - Check if the stack is empty.
  - Decrement `top`.

- **Peek**
  - Return `arr[top]` if the stack is not empty.

- **isEmpty**
  - Returns `true` if `top == -1`.

- **isFull**
  - Returns `true` if `top == size - 1`.

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

**Space Complexity:** `O(N)`

---

# Interview Notes

- Stack follows the **LIFO (Last In, First Out)** principle.
- `top` always points to the last inserted element.
- Initially, `top = -1`, indicating an empty stack.
- Overflow occurs when trying to push into a full stack.
- Underflow occurs when trying to pop from an empty stack.
- Array implementation is simple and provides `O(1)` operations but has a fixed capacity.

---

# What I Learned ⭐

- A stack can be implemented efficiently using an array and a single `top` pointer.
- All stack operations take constant time.
- The `top` pointer is the only state needed to manage insertions and deletions.
- Array-based stacks are simple and memory-efficient but cannot grow dynamically beyond their fixed capacity.