class Solution {
public:
    int solve(TreeNode* root,int ans)
    {
        if(root == NULL) return 0;        
        int value = root->val;
        ans = ans*2 + value;        
        if(root->left ==NULL && root->right ==NULL)
            return ans;
        return solve(root->left,ans) + solve(root->right,ans);
    }    
    int sumRootToLeaf(TreeNode* root) {
        return solve(root,0);
    }
};