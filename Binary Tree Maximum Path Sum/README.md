<center><h1>Binary Tree Maximum Path Sum</h1></center>

### Introduction
A root node of a tree will be provided as the input, we should find out the **path** that has the maxmium value sum.

A **path** is a sequence consisting of many nodes with an edge connected, each of which can appear **at most once**.

**Path sum** is the summation of a speicfied **path**.

Example:

![](https://hackmd.io/_uploads/Hk4aiTcws.png)
```cpp
root = [1, 2, 3]
output: 6
```

![](https://hackmd.io/_uploads/rks73T9Ds.png)

```cpp
root = [-10,9,20,null,null,15,7]
output: 42
```

### Method
DFS (Depth first search) algorithm can help us to solove this problem:
1. Calculate the summation of the right sub-tree, and return 0 if negative.
2. Do the same thing to the left sub-tree.
3. Store the result of `max(sumRight + sumLeft + root->val, maxSum)` as in golbal varialbe `maxSum`.
4. After all the recursive progress, the `maxSum` is what we want.

### Code
```cpp
class Solution {
private:
    int maxSum = numeric_limits<int>::min();
    
    int getSum(TreeNode* root){
        if(!root) return 0;
        
        int sumRight = max(getSum(root->right), 0);
        int sumLeft = max(getSum(root->left), 0);
        
        maxSum = max(sumRight + sumLeft + root->val, maxSum);
        
        return max(sumRight + root->val, sumLeft + root->val);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        getSum(root);
        return maxSum;
    }
};
```

###### tags: `Leetcode`