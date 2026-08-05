# Implement Stack using Linked List

## Problem Statement

Implement a **Stack** using a **Linked List**.

The stack should support the following operations:

- `push(x)` → Insert an element at the top of the stack.
- `pop()` → Remove the top element from the stack.
- `peek()` → Return the top element. If the stack is empty, return `-1`.
- `isEmpty()` → Return `true` if the stack is empty, otherwise `false`.
- `size()` → Return the number of elements currently present in the stack.

Unlike an array-based implementation, the stack should grow dynamically until memory is exhausted.

### Example

**Input**
```
push(5)
push(3)
push(4)
peek()
pop()
size()
isEmpty()
```

**Output**
```
4
2
false
```

**Explanation**

```
Initially

NULL

push(5)

5 -> NULL

push(3)

3 -> 5 -> NULL

push(4)

4 -> 3 -> 5 -> NULL

peek()

Top = 4

pop()

3 -> 5 -> NULL

size() = 2

isEmpty() = false
```

---

# Approach

## Key Idea

A stack follows the **LIFO (Last In, First Out)** principle.

Instead of storing elements in an array, we store them in a **Singly Linked List**.

We maintain:

- `top` → Pointer to the top node.
- `n` → Current number of elements in the stack.

Initially,

```
top = NULL
n = 0
```

Operations:

- **Push**
  - Create a new node.
  - Point it to the current top.
  - Update `top` to the new node.
  - Increment the size.

- **Pop**
  - Check if the stack is empty.
  - Store the current top node.
  - Move `top` to the next node.
  - Delete the old top node.
  - Decrement the size.

- **Peek**
  - Return the data of the top node.

- **isEmpty**
  - Returns `true` if `top == NULL`.

- **size**
  - Returns the current number of elements.

Since insertion and deletion always happen at the head of the linked list, every operation takes constant time.

## Code

```cpp
class myStack {

    Node* top;
    int n;

public:
    myStack() {
        top = nullptr;
        n = 0;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int x) {
        Node* head = new Node(x);
        head->next = top;
        top = head;
        n++;
    }

    void pop() {
        if (isEmpty()) return;

        Node* temp = top;
        top = top->next;
        delete temp;
        n--;
    }

    int peek() {
        if (isEmpty()) return -1;
        return top->data;
    }

    int size() {
        return n;
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
| size | `O(1)` |

**Space Complexity:** `O(N)`

---

# Interview Notes

- Stack follows the **LIFO (Last In, First Out)** principle.
- The **head node** of the linked list always represents the top of the stack.
- Insertion and deletion at the head take constant time.
- Unlike an array-based implementation, a linked-list stack grows dynamically and does not have a fixed capacity.
- Always check whether the stack is empty before performing a `pop()` operation.

---

# What I Learned ⭐

- A stack can be implemented efficiently using a singly linked list.
- The head pointer naturally acts as the top of the stack.
- Push and pop operations are performed at the head to achieve **O(1)** time complexity.
- Linked-list implementation removes the fixed-size limitation of array-based stacks and allows dynamic memory allocation.