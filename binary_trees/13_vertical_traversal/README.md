# Vertical Traversal of Binary Tree

## Problem Statement
Given the root of a binary tree, return its vertical order traversal.

- Nodes are grouped by their vertical columns.
- Columns are ordered from left to right.
- Within each column, nodes are ordered from top to bottom.
- If multiple nodes share the same row and column, sort them by value in ascending order.

## Examples

### Example 1
**Input:** `root = [3,9,20,null,null,15,7]`

**Output:** `[[9],[3,15],[20],[7]]`

### Example 2
**Input:** `root = [1,2,3,4,5,6,7]`

**Output:** `[[4],[2],[1,5,6],[3],[7]]`

## Observations
- Root coordinates are `(0,0)`.
- Left child coordinates are `(x-1,y+1)`.
- Right child coordinates are `(x+1,y+1)`.
- Use a nested map to maintain column and level order.
- Use a multiset to sort nodes sharing the same coordinates.

## Approach

- Use BFS to traverse the tree level by level.
- Store each node in `mp[x][y]`, where `x` is the column and `y` is the level.
- Use `map<int, map<int, multiset<int>>>` to maintain the required ordering automatically.
- Traverse the outer map to collect columns from left to right.
- Traverse each inner map to collect levels from top to bottom, adding all node values to the column vector.

### Code
```cpp
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }

        queue<pair<TreeNode*, pair<int,int>>> q;
        map<int, map<int, multiset<int>>> mp;

        q.push({root, {0,0}});

        while(!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();

            int x = pos.first;
            int y = pos.second;

            mp[x][y].insert(node->val);

            if(node->left) {
                q.push({node->left, {x-1,y+1}});
            }

            if(node->right) {
                q.push({node->right, {x+1,y+1}});
            }
        }

        for(auto x : mp) {
            vector<int> col;

            for(auto y : x.second) {
                col.insert(col.end(),
                           y.second.begin(),
                           y.second.end());
            }

            ans.push_back(col);
        }

        return ans;
    }
};
```

### Complexity
- **Time:** `O(N log N)` — map and multiset insertions maintain sorted order.
- **Space:** `O(N)` — maps, multisets, and the BFS queue store nodes and their positions.

## Key Takeaways
- **BFS** processes nodes level by level.
- **Coordinates** determine each node's column and level.
- **Outer map** sorts columns from left to right.
- **Inner map** sorts levels from top to bottom.
- **Multiset** sorts values when nodes share the same coordinates.