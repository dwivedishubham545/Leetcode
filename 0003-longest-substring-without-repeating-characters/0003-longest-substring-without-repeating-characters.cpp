class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, len=0;
        int n = s.size();
        unordered_map<char,int>mp;
        while(r<n){
            if(mp.find(s[r])!=mp.end()){
                l = max(mp[s[r]] + 1, l);
            }
            mp[s[r]]=r;
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};