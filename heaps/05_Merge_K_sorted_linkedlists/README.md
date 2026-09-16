# Merge K Sorted Lists

## Problem Statement

Given `k` sorted linked lists, merge them into one sorted linked list.

### Examples

**Input:**
```text
lists = [[1,4,5],[1,3,4],[2,6]]
```

**Output:**
```text
[1,1,2,3,4,4,5,6]
```

**Input:**
```text
lists = []
```

**Output:**
```text
[]
```

## Observations

- Each linked list is already sorted.
- We need to repeatedly find the smallest current node among all `k` lists.
- A min heap can give the smallest node in `O(log K)` time.
- Initially, put the head of every non-empty list into the heap.
- After removing a node, push its `next` node into the heap.

## Brute Force

- Traverse all lists and store every value in a vector.
- Sort all the values.
- Create a new linked list using the sorted values.
- We don't use the fact that the individual lists are already sorted.

```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        vector<int> v;

        for(ListNode* ll : lists){
            while(ll != NULL){
                v.push_back(ll->val);
                ll = ll->next;
            }
        }

        sort(v.begin(), v.end());

        ListNode* tail = &dummy;

        for(int x : v){
            tail->next = new ListNode(x);
            tail = tail->next;
        }

        return dummy.next;
    }
};
```

### Complexity

- **Time:** `O(N) + O(N log N) + O(N)` — traverse, sort, and create the result list → **O(N log N)**
- **Space:** `O(N)` — store all `N` values.

## Better Approach

- Merge the linked lists two at a time.
- First merge list `0` and list `1`, then merge the result with list `2`, and so on.
- This reuses the existing nodes and avoids storing all values separately.
- However, the merged list becomes larger after every merge.

```cpp
class Solution {
public:
    ListNode* merge2ll(ListNode* head1, ListNode* head2) {
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(head1 != NULL && head2 != NULL) {
            if(head1->val <= head2->val) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }

        if(head1 != NULL)
            tail->next = head1;
        else
            tail->next = head2;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;

        ListNode* head1 = lists[0];

        for(int i = 1; i < lists.size(); i++) {
            head1 = merge2ll(head1, lists[i]);
        }

        return head1;
    }
};
```

### Complexity

Let `N` be the number of nodes in each list and `K` be the number of lists.

- **Time:** `O(2N + 3N + 4N + ... + KN)` — each merge processes an increasingly larger list → **O(N × K(K+1)/2)**
- **Space:** `O(1)` — only pointers and a dummy node are used.

## Optimal Approach

- Use a **min heap** containing the current smallest node from each list.
- Initially push the head of every non-empty list.
- Remove the smallest node, attach it to the result, and push its `next` node.
- The heap contains at most `K` nodes at any time.

```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        struct compare {
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        };

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!pq.empty()) {
            ListNode* mini = pq.top();
            pq.pop();

            tail->next = mini;
            tail = tail->next;

            if(mini->next != NULL) {
                pq.push(mini->next);
            }
        }

        return dummy.next;
    }
};
```

### Complexity

- **Time:** `O(N log K) + O(K log K)` — process all `N` nodes and initially push up to `K` heads → `O((N+K) log K)` → **O(N log K)**
- **Space:** `O(K)` — the min heap contains at most `K` nodes.

## Key Takeaways

- **K sorted lists → Min Heap / K-way merge.**
- Keep one current node from each list in the heap.
- Pop the smallest node and push its `next` node.
- Use this pattern whenever you need to merge multiple sorted sequences efficiently.
- Optimal complexity: **O(N log K)** time and **O(K)** space.