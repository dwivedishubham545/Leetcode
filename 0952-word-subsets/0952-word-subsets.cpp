class Solution {
public:
    vector<int> count(const string& S) {
        vector<int> ans(26, 0);
        for (char c : S)
            ans[c - 'a']++;
        return ans;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> bmax(26, 0);
        for (const string& b : words2) {
            vector<int> bCount = count(b);
            for (int i = 0; i < 26; ++i)
                bmax[i] = max(bmax[i], bCount[i]);
        }

        vector<string> ans;
        for (const string& a : words1) {
            vector<int> aCount = count(a);
            bool isSubset = true;
            for (int i = 0; i < 26; ++i) {
                if (aCount[i] < bmax[i]) {
                    isSubset = false;
                    break;
                }
            }
            if (isSubset)
                ans.push_back(a);
        }

        return ans;
    }
};