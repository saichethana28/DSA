# Burning Tree — GFG

## Problem Statement
Given the root of a binary tree and a target node value, find the minimum time required to burn the entire tree.

The fire starts at the target node. In one second, the fire spreads to the node's left child, right child, and parent.

## Examples

### Example 1
Input: `root = [1, 2, 3, 4, 5, 6, 7]`, `target = 2`

Output: `3`

Explanation: The fire starts at node 2 and spreads to its adjacent nodes each second until the entire tree is burnt.

### Example 2
Input: `root = [1, 2, 3]`, `target = 1`

Output: `1`

Explanation: The fire spreads from node 1 to nodes 2 and 3 in one second.

## Observations
- A binary tree normally allows movement only from parent to children.
- To spread the fire upwards, store each node's parent in a map.
- Use BFS starting from the target node.
- Each BFS level represents the spread of fire to the next set of nodes.
- Use a visited map to prevent burning the same node more than once.
- Increment the time only when at least one new node gets burnt.

## Approach

- **Step 1: Mark parents**
  - Traverse the tree using BFS.
  - Store each node's parent in `mp`.
  - Identify the target node using its data value.

- **Step 2: Start burning**
  - Push the target node into the queue.
  - Mark it as visited.
  - Process each level and spread the fire to the left child, right child, and parent if they are unvisited.

- **Step 3: Calculate time**
  - Use `burnt` to track whether any new node catches fire during the current iteration.
  - Increment `level` only if a new node is burnt.
  - Return `level` after all nodes have been processed.

```cpp
class Solution {
public:
    void markparents(Node* root, unordered_map<Node*, Node*>& mp,
                     int k, Node*& target) {
        if (root == NULL) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();

                if (curr->data == k) {
                    target = curr;
                }

                if (curr->left) {
                    mp[curr->left] = curr;
                    q.push(curr->left);
                }

                if (curr->right) {
                    mp[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> mp;
        unordered_map<Node*, bool> visited;

        Node* target_node = NULL;
        markparents(root, mp, target, target_node);

        if (target_node == NULL) return 0;

        queue<Node*> q;
        q.push(target_node);
        visited[target_node] = true;

        int level = 0;

        while (!q.empty()) {
            int n = q.size();
            bool burnt = false;

            for (int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();

                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                    burnt = true;
                }

                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                    burnt = true;
                }

                if (mp.find(curr) != mp.end() &&
                    !visited[mp[curr]]) {
                    q.push(mp[curr]);
                    visited[mp[curr]] = true;
                    burnt = true;
                }
            }

            if (burnt) level++;
        }

        return level;
    }
};
```

### Complexity
Let `N` be the number of nodes in the binary tree.

- **Time:** `O(N)` — each node is processed at most once during parent mapping and once during BFS.
- **Space:** `O(N)` — the parent map, visited map, and queue can store up to `N` nodes.

## Key Takeaways
- Store parent pointers to enable upward traversal.
- BFS simulates the spread of fire level by level.
- The target node is the starting point of the fire.
- Mark nodes visited when adding them to the queue.
- Increment time only when the fire spreads to at least one new node.