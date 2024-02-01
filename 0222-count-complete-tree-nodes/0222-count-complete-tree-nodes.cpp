/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrderTraversal(TreeNode* root,vector<int> &ans){
    if (root == NULL){
        return;
    }
    inOrderTraversal(root->left,ans);
    ans.push_back(root->val);
    inOrderTraversal(root->right,ans);
}
    int countNodes(TreeNode* root) {
        vector<int>ans;
        inOrderTraversal(root,ans);
        return ans.size();
    }
};