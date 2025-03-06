class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cnt++;
                mp[grid[i][j]]++;
            }
        }
        int rep=0,mis=0;
        for(int i=1;i<=cnt;i++){
            if(mp[i]==1){
                continue;
            }else if(mp[i]==0){
                mis=i;
            }else{
                rep=i;
            }
        }
        ans.push_back(rep);
        ans.push_back(mis);
        return ans;
    }
};