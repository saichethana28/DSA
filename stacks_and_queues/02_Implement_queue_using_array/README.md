# Implement Queue using Array

## Problem Statement

Implement a **Queue** using a fixed-size array of capacity `n`.

The queue should support the following operations:

- `enqueue(x)` → Insert an element at the rear of the queue.
- `dequeue()` → Remove the front element of the queue.
- `getFront()` → Return the front element. If the queue is empty, return `-1`.
- `getRear()` → Return the rear element. If the queue is empty, return `-1`.
- `isEmpty()` → Return `true` if the queue is empty, otherwise `false`.
- `isFull()` → Return `true` if the queue is full, otherwise `false`.

### Example

**Input**
```
Capacity = 3

enqueue(5)
enqueue(3)
enqueue(4)
getFront()
dequeue()
isEmpty()
getRear()
```

**Output**
```
5
false
4
```

**Explanation**

```
Initially

[]

enqueue(5)

[5]

enqueue(3)

[5, 3]

enqueue(4)

[5, 3, 4]

getFront()

Front = 5

dequeue()

[3, 4]

isEmpty() = false

getRear() = 4
```

---

# Approach

## Key Idea

A queue follows the **FIFO (First In, First Out)** principle.

To efficiently utilize the fixed-size array, we implement the queue as a **Circular Queue**.

We maintain:

- `start` → Index of the front element.
- `end` → Index of the rear element.
- `curr` → Current number of elements in the queue.
- A fixed-size array to store the elements.

Initially,

```
start = 0
end = -1
curr = 0
```

Operations:

- **Enqueue**
  - Check if the queue is full.
  - Move `end` to the next circular position.
  - Insert the element.
  - Increment `curr`.

- **Dequeue**
  - Check if the queue is empty.
  - Move `start` to the next circular position.
  - Decrement `curr`.

- **getFront**
  - Return `arr[start]`.

- **getRear**
  - Return `arr[end]`.

- **isEmpty**
  - Returns `true` if `curr == 0`.

- **isFull**
  - Returns `true` if `curr == size`.

The circular movement is achieved using:

```
(index + 1) % size
```

This allows the queue to reuse empty positions instead of wasting space.

## Code

```cpp
class myQueue {

public:
    int curr;
    int start;
    int end;
    int size;
    vector<int> arr;

    myQueue(int n) {
        size = n;
        curr = 0;
        start = 0;
        end = -1;
        arr.resize(n);
    }

    bool isEmpty() {
        return curr == 0;
    }

    bool isFull() {
        return curr == size;
    }

    void enqueue(int x) {
        if (isFull()) return;

        end = (end + 1) % size;
        arr[end] = x;
        curr++;
    }

    void dequeue() {
        if (isEmpty()) return;

        start = (start + 1) % size;
        curr--;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[start];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[end];
    }
};
```

## Complexity Analysis

| Operation | Time Complexity |
|-----------|-----------------|
| Enqueue | `O(1)` |
| Dequeue | `O(1)` |
| getFront | `O(1)` |
| getRear | `O(1)` |
| isEmpty | `O(1)` |
| isFull | `O(1)` |

**Space Complexity:** `O(N)`

---

# Interview Notes

- Queue follows the **FIFO (First In, First Out)** principle.
- A **Circular Queue** avoids wasting space after dequeue operations.
- `start` always points to the front element.
- `end` always points to the rear element.
- `curr` keeps track of the number of elements, making `isEmpty()` and `isFull()` simple.
- Circular indexing using `(index + 1) % size` allows efficient reuse of array positions.

---

# What I Learned ⭐

- A queue can be efficiently implemented using a circular array.
- Maintaining `start`, `end`, and `curr` enables all queue operations in constant time.
- Circular queues eliminate the space wastage problem of a normal linear queue.
- Modulo arithmetic is the key to wrapping around the array and reusing available positions.