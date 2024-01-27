class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int>v1;
        vector<int>v2;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                v2.push_back(nums[i]);
            }else{
                v1.push_back(nums[i]);
            }
        }
        nums.clear();
        for(int i=0;i<v1.size();i++){
            nums.push_back(v1[i]);
        }
        for(int i=0;i<v2.size();i++){
            nums.push_back(v2[i]);
        }
    }
};