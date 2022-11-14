<center><h1>Kth Smallest Element in a BST</h1></center>

[Leetcode Link](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

### Intorduce
In this problem, a BST and a integer k will be provided as inputs, we should return the k-th smallest element of this BST.

### Binary Search Tree (BST)
A important property of BST we should know before starting solve this problem:
>For each node n, the value of its left child node will smaller than that of n, and the value of right node will bigger than that of n.

### Method
After we know that property of BST, we can solve this problem easily with these two steps:
1. Initialize a vector.
2. Flatten the input BST with DFS, but left child first.
3. Return the k-th number of the vector.

Visualization:<br>
![](https://i.imgur.com/pksPTMr.png)



### Code
```cpp
class Solution {
public:
    vector<int> res;
    
    void dfs(TreeNode* root)
    {
        if(!root) return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return res[k-1];
    }
};
```

### Optimization
The solution can be optimized to O(k) with a if statement.

```cpp
class Solution {
public:
    vector<int> res;
    
    void dfs(TreeNode* root, int k)
    {
        if(res.size() >= k) return;
        if(!root) return;
        dfs(root->left, k);
        res.push_back(root->val);
        dfs(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res[k-1];
    }
};
```

###### tags: `Leetcode`
