class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        long long n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        long long currSum = 0;
        long long remSum = 0;
        long long ans = 0;
        for(int i=0;i<n-1;i++){
            currSum += nums[i];
            remSum = sum-currSum;
            if(currSum>=remSum){
                ans++;
            }
        }
        return ans;
    }
};