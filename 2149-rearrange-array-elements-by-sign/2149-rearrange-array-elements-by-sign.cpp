class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        vector<int>combined;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }else{
                pos.push_back(nums[i]);
            }
        }
        for(int i=0;i<nums.size()/2;i++){
            combined.push_back(pos[i]);
            combined.push_back(neg[i]);
        }
        return combined;
    }
};