# Implement Queue using Linked List

## Problem Statement

Implement a **Queue** using a **Linked List**.

The queue should support the following operations:

- `enqueue(x)` → Insert an element at the rear of the queue.
- `dequeue()` → Remove the front element of the queue.
- `getFront()` → Return the front element. If the queue is empty, return `-1`.
- `isEmpty()` → Return `true` if the queue is empty, otherwise `false`.
- `size()` → Return the number of elements currently present in the queue.

Unlike an array-based implementation, the queue should grow dynamically until memory is exhausted.

### Example

**Input**
```
enqueue(5)
enqueue(3)
enqueue(4)
getFront()
dequeue()
size()
isEmpty()
```

**Output**
```
5
2
false
```

**Explanation**

```
Initially

NULL

enqueue(5)

Front
 ↓
5 → NULL
 ↑
Rear

enqueue(3)

Front
 ↓
5 → 3 → NULL
     ↑
    Rear

enqueue(4)

Front
 ↓
5 → 3 → 4 → NULL
         ↑
        Rear

getFront()

Front = 5

dequeue()

Front
 ↓
3 → 4 → NULL
     ↑
    Rear

size() = 2

isEmpty() = false
```

---

# Approach

## Key Idea

A queue follows the **FIFO (First In, First Out)** principle.

Instead of storing elements in an array, we store them in a **Singly Linked List**.

We maintain:

- `start` → Pointer to the front node.
- `end` → Pointer to the rear node.
- `n` → Current number of elements in the queue.

Initially,

```
start = NULL
end = NULL
n = 0
```

Operations:

- **Enqueue**
  - Create a new node.
  - If the queue is empty, both `start` and `end` point to the new node.
  - Otherwise, attach the new node after `end` and update `end`.
  - Increment the size.

- **Dequeue**
  - Check if the queue is empty.
  - Remove the front node.
  - Move `start` to the next node.
  - If the queue becomes empty, set `end = NULL`.
  - Decrement the size.

- **getFront**
  - Return the data of the front node.

- **isEmpty**
  - Returns `true` if `n == 0`.

- **size**
  - Returns the current number of elements.

Since insertion happens at the rear and deletion happens at the front, every operation takes constant time.

## Code

```cpp
class myQueue {

public:
    Node* start;
    Node* end;
    int n;

    myQueue() {
        start = nullptr;
        end = nullptr;
        n = 0;
    }

    bool isEmpty() {
        return n == 0;
    }

    void enqueue(int x) {

        Node* temp = new Node(x);

        if(isEmpty()) {
            start = temp;
            end = temp;
        }
        else {
            end->next = temp;
            end = temp;
        }

        n++;
    }

    void dequeue() {

        if(isEmpty()) return;

        Node* temp = start;
        start = start->next;

        if(start == nullptr)
            end = nullptr;

        delete temp;
        n--;
    }

    int getFront() {

        if(isEmpty())
            return -1;

        return start->data;
    }

    int size() {
        return n;
    }
};
```

## Complexity Analysis

| Operation | Time Complexity |
|-----------|-----------------|
| Enqueue | `O(1)` |
| Dequeue | `O(1)` |
| getFront | `O(1)` |
| isEmpty | `O(1)` |
| size | `O(1)` |

**Space Complexity:** `O(N)`

---

# Interview Notes

- Queue follows the **FIFO (First In, First Out)** principle.
- The **front pointer** always points to the first element, while the **rear pointer** points to the last element.
- Insertion happens at the rear, and deletion happens at the front.
- Unlike an array-based queue, a linked-list queue has no fixed capacity and grows dynamically.
- When removing the last element, both `start` and `end` should be updated to `NULL` to avoid dangling pointers.

---

# What I Learned ⭐

- A queue can be efficiently implemented using a singly linked list with two pointers.
- Maintaining both `start` and `end` allows enqueue and dequeue operations to run in constant time.
- Linked-list implementation eliminates the fixed-size limitation of array-based queues.
- Properly handling the case when the queue becomes empty is important to avoid invalid pointers.