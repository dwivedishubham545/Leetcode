class Solution {
public:
    string reverseWords(string s) {
        string st = "";
        vector<string> str;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ') {
                st += s[i];
            } else {
                if(!st.empty()) {  
                    str.push_back(st);
                    st = "";
                }
            }
        }
        if(!st.empty()) {  
            str.push_back(st);
        }

        reverse(str.begin(), str.end());

        string ans = ""; 
        for(int i = 0; i < str.size(); i++) {
            ans += str[i];
            if(i != str.size() - 1) {
                ans += ' ';
            }
        }
        
        return ans;
    }
};
