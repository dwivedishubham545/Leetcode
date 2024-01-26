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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
    if(root == NULL) return ans;

    queue<TreeNode*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size); // Change here: size of temp is set to size of the level

        for(int i = 0; i < size; i++){
            TreeNode* curr = q.front();
            q.pop();
            
            // Fill in the correct position based on the traversal direction
            int index = leftToRight ? i : size - 1 - i;
            temp[index] = curr->val;

            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }

        // Add the current level to the answer
        ans.push_back(temp);
        leftToRight = !leftToRight;
    }

    return ans;
    }
};