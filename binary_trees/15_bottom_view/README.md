# Bottom View of Binary Tree

## Problem Statement
Given the root of a binary tree, return the bottom view of the tree.

The bottom view contains the nodes visible when the tree is viewed from below, ordered from left to right.

## Examples

### Example 1
**Input:**
```text
        1
       / \
      2   3
       \   \
        4   6
         \
          5
```

**Output:** `[2, 4, 5, 6]`

### Example 2
**Input:**
```text
        1
       / \
      2   3
```

**Output:** `[2, 1, 3]`

## Observations
- Assign the root a horizontal distance of `0`.
- The left child gets `line - 1`.
- The right child gets `line + 1`.
- If multiple nodes have the same horizontal distance, the bottommost node is considered visible.
- BFS processes nodes level by level.
- An ordered map maintains horizontal distances from left to right.

## Approach

- Use a queue to perform BFS, storing each node with its horizontal distance.
- Use a map to store the latest node encountered at each horizontal distance.
- Overwrite the map entry whenever another node has the same horizontal distance.
- Move left by decreasing the distance and right by increasing it.
- Traverse the map to collect the bottom view from left to right.

### Code
```cpp
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        queue<pair<Node*, int>> q;
        map<int, int> mp;

        q.push({root, 0});

        while(!q.empty()) {
            auto [node, line] = q.front();
            q.pop();

            mp[line] = node->data;

            if(node->left) {
                q.push({node->left, line - 1});
            }

            if(node->right) {
                q.push({node->right, line + 1});
            }
        }

        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
```

### Complexity
- **Time:** `O(N log N)` — each node may require a map operation.
- **Space:** `O(N)` — the queue and map may store up to `N` nodes or entries.

## Key Takeaways
- **BFS** visits nodes level by level.
- **Horizontal distance** identifies each vertical column.
- **Overwrite the map entry** to keep the latest node at each horizontal distance.
- **Ordered map** automatically sorts columns from left to right.
- Unlike top view, bottom view updates the value every time a node at the same horizontal distance is encountered.