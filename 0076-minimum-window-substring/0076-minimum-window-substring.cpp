class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) {
            return "";
        }

        unordered_map<char, int> dictT;
        for (char c : t) {
            dictT[c]++;
        }

        int required = dictT.size();
        int l = 0, r = 0, formed = 0;
        unordered_map<char, int> windowCounts;
        vector<int> ans = {numeric_limits<int>::max(), 0, 0}; // length, left, right

        while (r < s.length()) {
            char c = s[r];
            windowCounts[c]++;

            if (dictT.find(c) != dictT.end() && windowCounts[c] == dictT[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                c = s[l];
                if (r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }

                windowCounts[c]--;
                if (dictT.find(c) != dictT.end() && windowCounts[c] < dictT[c]) {
                    formed--;
                }

                l++;
            }
            r++;
        }

        return ans[0] == numeric_limits<int>::max() ? "" : s.substr(ans[1], ans[0]);
    }
};