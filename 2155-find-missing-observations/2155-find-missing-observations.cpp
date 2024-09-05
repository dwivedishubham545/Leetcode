class Solution {
public:
    int sum(vector<int>&rolls){
        int s=0;
        for(auto x : rolls){
            s+=x;
        }
        return s;
    }
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int nTotal = (mean * (n+m)) - sum(rolls);
        vector<int>res;
        if(nTotal < n || nTotal > n*6){
            return res;
        } 
        while(nTotal){
            int dice = min(nTotal - n + 1, 6);
            res.push_back(dice);
            nTotal -= dice;
            n -= 1;
        }
        return res;
    }
};