class Solution {
public:
    long long minimumSteps(string s) {
        int l=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!='1'){
                l++;
            }else{
                break;
            }
        }

        int r=l;
        long long cnt=0;
        for(int i=l;i<s.length();i++){
            if(s[i]=='1'){
                r++;
            }else{
                cnt += (r-l);
                l++;
                r++;
            }
        }
        return cnt;
    }
};