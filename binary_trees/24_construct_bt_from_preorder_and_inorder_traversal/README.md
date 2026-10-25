# 105. Construct Binary Tree from Preorder and Inorder Traversal

## Problem Statement
Given two integer arrays `preorder` and `inorder`, construct and return the binary tree.

- **Preorder:** Root → Left → Right
- **Inorder:** Left → Root → Right

Assume all elements are unique.

## Examples

### Example 1
Input: `preorder = [3,9,20,15,7]`, `inorder = [9,3,15,20,7]`

Output: `[3,9,20,null,null,15,7]`

### Example 2
Input: `preorder = [-1]`, `inorder = [-1]`

Output: `[-1]`

## Observations
- The first element of preorder is always the root.
- Find the root's position in inorder to separate the left and right subtrees.
- The number of elements in the left subtree is `in_root - istart`.
- Use a hashmap to find the root's inorder index in `O(1)` average time.
- Recursively construct the left and right subtrees using their respective traversal ranges.

## Approach

- Store each inorder element's index in an `unordered_map`.
- Select `preorder[pstart]` as the root.
- Find the root's inorder index using `mp[preorder[pstart]]`.
- Calculate the number of left subtree nodes using `l = in_root - istart`.
- Recursively construct:
  - **Left subtree:** Preorder range `[pstart + 1, pstart + l]`, Inorder range `[istart, in_root - 1]`.
  - **Right subtree:** Preorder range `[pstart + l + 1, pend]`, Inorder range `[in_root + 1, iend]`.
- Return the constructed root.

```cpp
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int pstart, int pend, int istart, int iend,
                    unordered_map<int, int>& mp) {
        if (pstart > pend || istart > iend) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[pstart]);

        int in_root = mp[preorder[pstart]];
        int l = in_root - istart;

        root->left = solve(preorder, inorder,
                           pstart + 1, pstart + l,
                           istart, in_root - 1, mp);

        root->right = solve(preorder, inorder,
                            pstart + 1 + l, pend,
                            in_root + 1, iend, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, inorder, 0, n - 1, 0, n - 1, mp);
    }
};
```

### Complexity
Let `N` be the number of nodes.

- **Time:** `O(N)` — each node is constructed once, and hashmap lookups take `O(1)` average time.
- **Space:** `O(N)` — the hashmap requires `O(N)` space, and the recursive stack requires up to `O(N)` space in the worst case.

## Key Takeaways
- Preorder identifies the root.
- Inorder separates the left and right subtrees.
- The left subtree size is `in_root - istart`.
- A hashmap avoids repeatedly searching the inorder array.
- Use index ranges instead of creating new arrays for every recursive call.