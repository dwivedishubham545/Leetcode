class Solution {
public:
    void solve(vector<int>& nums, vector<int>& ans, int index, set<vector<int>>& output) {
        if (index == nums.size()) {
            output.insert(ans); 
            return;
        }

        ans.push_back(nums[index]);
        solve(nums, ans, index + 1, output);

        ans.pop_back();
        solve(nums, ans, index + 1, output);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> output; 
        vector<int> ans;
        sort(nums.begin(), nums.end()); 
        solve(nums, ans, 0, output);

        vector<vector<int>> output2(output.begin(), output.end());
        return output2;
    }
};
