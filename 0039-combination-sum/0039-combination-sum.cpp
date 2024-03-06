class Solution {
private:
        void findcombSum(int index, vector<int>&nums, int target, vector<vector<int>>&ans, vector<int>&result){
            if(index==nums.size()){
                if(target==0){
                    ans.push_back(result);
                }
                return;
            }
            if(nums[index]<=target){
                result.push_back(nums[index]);
                findcombSum(index,nums,target-nums[index],ans,result);
                result.pop_back();
            }
            findcombSum(index+1,nums,target,ans,result);
        }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> result;
        findcombSum(0,candidates,target,ans,result);
        return ans;
    }
};