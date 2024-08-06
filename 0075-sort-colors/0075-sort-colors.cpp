class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>v(nums.size(),-1);
        int k=0;
        int j=v.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                v[k]=0;
                k++;
            }else if(nums[i]==2){
                v[j]=2;
                j--;
            }else{
                continue;
            }
        }
        while(k<=j){
            v[k]=1;
            k++;
        }
        nums = v;
    }
};