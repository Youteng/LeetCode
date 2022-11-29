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