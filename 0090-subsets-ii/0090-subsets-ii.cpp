class Solution {
public:
    void solve(vector<int>& nums, vector<int>& ans, int index, vector<vector<int>>& output) {
        if (index == nums.size()) {
            output.push_back(ans); 
            return;
        }

        ans.push_back(nums[index]);
        solve(nums, ans, index + 1, output);

        ans.pop_back();

        int i = index+1;
        while(i<nums.size()&&nums[i]==nums[i-1]){
            i++;
        }
        solve(nums, ans, i, output);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> output; 
        vector<int> ans;
        sort(nums.begin(), nums.end()); 
        solve(nums, ans, 0, output);

        // vector<vector<int>> output2(output.begin(), output.end());
        return output;
    }
};
