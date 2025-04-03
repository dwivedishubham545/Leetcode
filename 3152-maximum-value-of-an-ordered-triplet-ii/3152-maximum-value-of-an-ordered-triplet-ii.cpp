class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        long long maxi = 0;
        long long a = INT_MIN;
        int b = nums[0];

        for(int i = 1; i < n - 1; i++) {
            a = max(a, (long long)b - nums[i]); 
            maxi = max(maxi, a * nums[i + 1]);  
            b = max(b, nums[i]);
        }

        return maxi;
    }
};
