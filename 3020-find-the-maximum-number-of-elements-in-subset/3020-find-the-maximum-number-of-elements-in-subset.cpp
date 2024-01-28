class Solution {
public:
    int maximumLength(vector<int>& nums) {
  map<long long,int> m;
        for(auto it:nums)m[it]++;
        int ans=m[1];
        if(ans%2==0)ans--;
        for(auto it:m){
            if(it.first==1)continue;
            long long now=it.first;
            int cnt=0;
            while(m.find(now)!=m.end()&&m[now]>=2){
                cnt+=2;
                now=now*now;
            }
            if(m.find(now)==m.end())cnt--;
            else cnt++;
            ans=max(ans,cnt);
        }
        return ans;
    }
};