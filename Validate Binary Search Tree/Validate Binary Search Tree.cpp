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