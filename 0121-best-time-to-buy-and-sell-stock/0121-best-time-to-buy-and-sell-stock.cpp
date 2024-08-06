class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxPrice = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mini){
                mini = prices[i];
            }else{
                maxPrice = max(maxPrice,abs(prices[i]-mini));
            }
        }
        return maxPrice;
    }
};