class Solution {
public:
    bool isPalindrome(string S)
    {
        string P = S;
        reverse(P.begin(), P.end());
        if (S == P) {
            return true;
        }
        else {
            return false;
        }
    }
    string firstPalindrome(vector<string>& words) {
        string s ="";
        for(int i=0;i<words.size();i++){
            if(isPalindrome(words[i])){
                s = words[i];
                break;
            }
        }
        return s;
    }
};