class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(mp[s[i]]==1){
                ans = i;
                break;
            }else{
                ans = -1;
            }
        }
        return ans;
    }
};