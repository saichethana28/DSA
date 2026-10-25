# 863. All Nodes Distance K in Binary Tree

## Problem Statement
Given the root of a binary tree, a target node, and an integer `k`, return the values of all nodes that are exactly distance `k` from the target node.

The distance between two nodes is the number of edges along the shortest path between them.

## Examples

### Example 1
Input: `root = [3,5,1,6,2,0,8,null,null,7,4]`, `target = 5`, `k = 2`

Output: `[7,4,1]`

Explanation: The nodes at distance 2 from node 5 are 7, 4, and 1.

### Example 2
Input: `root = [1]`, `target = 1`, `k = 3`

Output: `[]`

## Observations
- A binary tree normally allows movement only from parent to children.
- To reach nodes above the target, we must also know each node's parent.
- Use an `unordered_map` to store parent pointers.
- Treat the tree as an undirected graph and perform BFS from the target.
- Use a visited map to prevent revisiting nodes.

## Approach

- **Step 1: Mark parents**
  - Traverse the tree using BFS.
  - Store each node's parent in `mp`.

- **Step 2: BFS from the target**
  - Initialise the queue with the target node.
  - Mark the target as visited.
  - Process one complete level at a time.
  - Explore the left child, right child, and parent if they have not been visited.
  - Stop when the BFS reaches distance `k`.

- **Step 3: Collect the answer**
  - The nodes remaining in the queue are exactly distance `k` from the target.
  - Collect their values and return the answer.

```cpp
class Solution {
public:
    void markparents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    mp[node->left] = node;
                    q.push(node->left);
                }

                if (node->right) {
                    mp[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        unordered_map<TreeNode*, bool> visited;

        markparents(root, mp);

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int curr_lvl = 0;

        while (!q.empty()) {
            int n = q.size();

            if (curr_lvl == k) {
                break;
            }

            curr_lvl++;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }

                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if (mp.find(node) != mp.end() && !visited[mp[node]]) {
                    q.push(mp[node]);
                    visited[mp[node]] = true;
                }
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
```

### Complexity
Let `N` be the number of nodes in the binary tree.

- **Time:** `O(N)` — marking parents and BFS each take linear time on average.
- **Space:** `O(N)` — the parent map, visited map, and queue can store up to `N` nodes.

## Key Takeaways
- Store parent pointers to move upwards in the tree.
- Convert the binary tree into an undirected graph conceptually.
- BFS finds nodes according to their distance from the target.
- Process the queue level by level to track distance.
- Mark nodes visited when adding them to the queue to avoid duplicates.