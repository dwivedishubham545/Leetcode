class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) nums[i]= -1*nums[i];
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]*nums[i]);
        }
        return v;
    }
};