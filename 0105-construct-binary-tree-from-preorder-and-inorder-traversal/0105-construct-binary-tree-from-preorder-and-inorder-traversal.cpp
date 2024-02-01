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
    TreeNode* buildTreeUtil(vector<int>& in, vector<int>& pre, int inStart, int inEnd, int &preIndex){
        if(inStart > inEnd) return NULL;
        
        TreeNode* tNode = new TreeNode(pre[preIndex++]);
        
        if(inStart == inEnd) return tNode;
        
        int inIndex = search(in, inStart, inEnd, tNode->val);
        
        tNode->left = buildTreeUtil(in, pre, inStart, inIndex-1, preIndex);
        tNode->right = buildTreeUtil(in, pre, inIndex+1, inEnd, preIndex);
        
        return tNode;
    }
    
    int search(vector<int>& arr, int start, int end, int x){
        for(int i=start; i<=end; i++){
            if(arr[i] == x) return i;
        }
        return -1;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        int n = inorder.size();
        return buildTreeUtil(inorder, preorder, 0, n-1, preIndex);
    }
};