class Solution {
public:
    vector<string>breakSen(string &s){
        vector<string>res;
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                res.push_back(temp);
                temp="";
            }else{
                temp+=s[i];
            }
        }
        res.push_back(temp);
        return res;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string>v1 = breakSen(sentence1);
        vector<string>v2 = breakSen(sentence2);

        while(v1.size()>0 && v2.size()>0 && v1.front()==v2.front()){
            v1.erase(v1.begin());
            v2.erase(v2.begin());
        }
        while(v1.size()>0 && v2.size()>0 && v1.back()==v2.back()){
            v1.pop_back();
            v2.pop_back();
        }

        return v1.size()==0 || v2.size()==0;
    }
};