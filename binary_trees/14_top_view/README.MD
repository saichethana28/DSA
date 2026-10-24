# Top View of Binary Tree

## Problem Statement
Given the root of a binary tree, return the top view of the tree.

The top view contains the nodes visible when the tree is viewed from above, ordered from left to right.

## Examples

### Example 1
**Input:**
```text
        1
       / \
      2   3
       \
        4
         \
          5
           \
            6
```

**Output:** `[2, 1, 3, 6]`

### Example 2
**Input:** `root = [1, 2, 3]`

**Output:** `[2, 1, 3]`

## Observations
- Assign the root a horizontal distance of `0`.
- Left child gets `line - 1`.
- Right child gets `line + 1`.
- If multiple nodes have the same horizontal distance, only the first encountered node is included.
- BFS ensures nodes are visited level by level.
- An ordered map stores horizontal distances from left to right.

## Approach

- Use a queue to perform BFS, storing each node with its horizontal distance.
- Use a map to store the first node encountered at each horizontal distance.
- Check whether the horizontal distance already exists before inserting.
- Move left by decreasing the distance and right by increasing it.
- Traverse the map to obtain the top view from left to right.

### Code
```cpp
class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }

        queue<pair<Node*, int>> q;
        map<int, int> mp;

        q.push({root, 0});

        while(!q.empty()) {
            auto [node, line] = q.front();
            q.pop();

            if(mp.find(line) == mp.end()) {
                mp[line] = node->data;
            }

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
- **Horizontal distance** identifies a node's vertical column.
- **First node wins:** insert only if the horizontal distance is absent.
- **Ordered map** automatically sorts columns from left to right.
- Top view requires only one node per horizontal distance.