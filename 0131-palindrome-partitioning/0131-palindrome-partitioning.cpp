class Solution {
public:
    void func(int indx , string s , vector<string>&temp , vector<vector<string>>&res){
        if(indx == s.size()){
            res.push_back(temp);
            return;
        }
        for(int i = indx ; i < s.size() ; i++){
            if(ispalindrome(s,indx,i)){
                temp.push_back(s.substr(indx,i-indx+1));
                func(i+1,s,temp,res);
                temp.pop_back();
            }
        }
    }
    bool ispalindrome(string s , int start , int end){
        while(start < end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
     vector<vector<string>> partition(string s){
        vector<vector<string>>res;
        vector<string>temp;
        func(0,s,temp,res);
        return res;
    }
};