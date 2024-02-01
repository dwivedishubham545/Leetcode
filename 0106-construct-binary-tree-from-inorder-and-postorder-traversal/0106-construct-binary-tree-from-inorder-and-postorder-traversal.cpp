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
    int search(vector<int>& arr, int start, int end, int x){
        for(int i=start; i<=end; i++){
            if(arr[i] == x) return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& in, vector<int>& post,int &postIndex, int inStart, int inEnd){
            if(inStart > inEnd) return NULL;

            TreeNode* tNode = new TreeNode(post[postIndex--]);

            if(inStart == inEnd) return tNode;

            int inIndex = search(in, inStart, inEnd, tNode->val);

            tNode->right = solve(in, post, postIndex, inIndex+1, inEnd);
            tNode->left = solve(in, post, postIndex, inStart, inIndex-1);

            return tNode;
        }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postOrderIndex = n-1;
        TreeNode* ans = solve(inorder, postorder, postOrderIndex, 0, n-1);
        return ans;
    }
};