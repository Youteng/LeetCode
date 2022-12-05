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