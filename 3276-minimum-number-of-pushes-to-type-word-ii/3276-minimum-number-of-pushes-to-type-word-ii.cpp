class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(int i=0;i<word.length();i++){
            mp[word[i]]++;
        }
        vector<int>v(26,0);
        int j=0;
        for(auto it:mp){
            v[j]=it.second;
            j++;
        }
        sort(v.rbegin(),v.rend());
        int n = v.size();
        int ans=0;
        for(int i=0;i<8;i++){
            ans+=v[i];
        }
        for(int i=8;i<16;i++){
            ans+=2*(v[i]);
        }
        for(int i=16;i<24;i++){
            ans+=3*(v[i]);
        }
        for(int i=24;i<26;i++){
            ans+=4*(v[i]);
        }
        return ans;
    }
};