class Solution {
    void findcombSum(int index, vector<int>&nums, int target, vector<vector<int>>&ans, vector<int>&result){
            if(target==0){
                ans.push_back(result);
                return;
            }
            for(int i=index;i<nums.size();i++){
                if(i>index && nums[i]==nums[i-1]){
                    continue;
                }
                if(nums[i]>target){
                    break;
                }
                result.push_back(nums[i]);
                findcombSum(i+1,nums,target-nums[i],ans,result);
                result.pop_back();
            }
        }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> result;
        findcombSum(0,candidates,target,ans,result);
        return ans;
    }
};