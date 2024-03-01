class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string st ="";
        int n = s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
            }
        }
        for(int i=0;i<cnt-1;i++){
            st+="1";
        }
        for(int i=0;i<n-cnt;i++){
            st+="0";
        }
        st+="1";
        return st;
    }
};