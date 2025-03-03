class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>x;
        vector<int>y;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                x.push_back(nums[i]);
            }else if(nums[i]>pivot){
                y.push_back(nums[i]);
            }else{
                cnt++;
            }
        }
        for(int i=0;i<cnt;i++){
            x.push_back(pivot);
        }
        for(int i=0;i<y.size();i++){
            x.push_back(y[i]);
        }
        return x;
    }
};