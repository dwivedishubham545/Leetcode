class Solution {
private:
    void solve(vector<int>nums,vector<int>ans,int index,vector<vector<int>>& output){
        if(index==nums.size()){
            output.push_back(ans);
            return;
        }

        ans.push_back(nums[index]);
        solve(nums,ans,index+1,output);
        ans.pop_back();
        solve(nums,ans,index+1,output);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>output;
        vector<int>ans;
        solve(nums,ans,0,output);
        return output;
    }
};