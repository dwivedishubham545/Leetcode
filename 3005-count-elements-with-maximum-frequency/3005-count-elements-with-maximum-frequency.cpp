class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>v;
        for(auto it : mp){
            v.push_back(it.second);
        }
        sort(v.rbegin(),v.rend());
        int cnt = v[0];
        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1]){
                cnt+=v[i];
            }else{
                break;
            }
        }
        return cnt;
    }
};