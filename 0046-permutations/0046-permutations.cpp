class Solution {
    void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &res, int freq[]){
        if(nums.size() == ds.size()){
            res.push_back(ds);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(ds, nums, res, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++){
            freq[i]=0;
        }
        recurPermute(ds, nums, res, freq);
        return res;
    }
};