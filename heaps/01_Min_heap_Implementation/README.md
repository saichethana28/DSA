# Min Heap Implementation

## Binary Heap

A **Binary Heap** is a **Complete Binary Tree** that satisfies the **Heap Property**.

- **Complete Binary Tree:** All levels are completely filled except possibly the last, which is filled from left to right.
- **Min Heap:** Every parent is smaller than or equal to its children. Hence, the minimum element is always at `arr[0]`.

## Array Representation

For a node at index `i`:

| Node | Index |
|---|---|
| Parent | `(i - 1) / 2` |
| Left Child | `2*i + 1` |
| Right Child | `2*i + 2` |

## Operations

- **Insert:** Add the element at the end and move it upward until the min-heap property is restored.
- **Heapify:** Move a node downward by repeatedly swapping it with the smaller child.
- **Peek:** Return the minimum element `arr[0]`.
- **Extract Min / Pop:** Replace the root with the last element, remove the last element, then heapify.
- **Decrease Key:** Decrease a value and move it upward until the heap property is restored.
- **Delete:** Decrease the value to `INT_MIN`, move it to the root, then extract it.

## Time Complexity

| Operation | Time |
|---|---|
| Insert | `O(log N)` |
| Heapify | `O(log N)` |
| Peek | `O(1)` |
| Extract Min | `O(log N)` |
| Decrease Key | `O(log N)` |
| Delete | `O(log N)` |

## C++ Implementation

```cpp
class minHeap {
private:
    int len = 0;
    vector<int> arr;

public:

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void push(int x) {
        arr.push_back(x);
        len++;

        int k = len - 1;

        while (k != 0 && arr[parent(k)] > arr[k]) {
            swap(arr[parent(k)], arr[k]);
            k = parent(k);
        }
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < len && arr[l] < arr[smallest])
            smallest = l;

        if (r < len && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    void pop() {
        if (len == 0)
            return;

        arr[0] = arr[len - 1];
        arr.pop_back();
        len--;

        if (len > 0)
            heapify(0);
    }

    int peek() {
        if (len == 0)
            return -1;

        return arr[0];
    }

    int size() {
        return len;
    }
};
```