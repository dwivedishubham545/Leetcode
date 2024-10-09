class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool ans = false; 
        for(int i = 0; i < n; i++) {
            ans = binary_search(matrix[i].begin(), matrix[i].end(), target);
            if(ans) {
                break; 
            }
        }
        return ans;
    }
};
