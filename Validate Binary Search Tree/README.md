<center><h1>Validate Binary Search Tree</h1></center>

### Introduction
The `root` of a tree is given, return whether this tree is a valid BST.

A *valid* should is defined as:
- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

Example:
```cpp
root = [2, 1, 3]
output: True
```

### Method
Using BFS can solve that easily:
1. Check if the value of root `r` is smaller than `max` and greater than `min`.
2. Move to check left child, then set `max` as the value of `r`.
3. Move to check right child, set the `min` as the value of `r`.
4. Recursively check the whole tree.
5. Return the answer.

### Code
```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
    
    bool check(TreeNode* root, long min, long max)
    {
        if(!root) return true;
        
        if(root->val < max && root->val > min)
        {
            return check(root->left, min, root->val) && check(root->right, root->val, max);
        }
        
        return false;
    }
};
```

###### tags: `Leetcode`