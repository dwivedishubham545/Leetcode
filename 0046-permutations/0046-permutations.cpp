class Solution {
    void recurPermute(vector<int> &nums, int ind, vector<vector<int>> &res){
        if(ind==nums.size()){
            res.push_back(nums);
        }

        for(int i=ind;i<nums.size();i++){
            swap(nums[ind], nums[i]);
            recurPermute(nums, ind+1, res);
            swap(nums[ind], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        recurPermute(nums,0,res);
        return res;
    }
};