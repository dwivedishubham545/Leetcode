class Solution {
public:
    int solve(int n , vector<int>&dp){
        if(n==0) return 0;
        if(n==1) return 1;
        if(dp[n]!=-1){
            return dp[n];
        }
        int mini = INT_MAX;
        for(int i=1;i*i<=n;i++){
            int rem = n-i*i;
            int count = solve(rem, dp);
            mini = min(mini, count);
        }
        return dp[n] = mini + 1; 
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};