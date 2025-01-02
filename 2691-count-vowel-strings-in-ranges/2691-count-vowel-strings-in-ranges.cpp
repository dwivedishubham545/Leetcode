class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        vector<int> prefix(words.size() + 1, 0);
        for (int i = 0; i < words.size(); i++) {
            if (vowels.count(words[i][0]) && vowels.count(words[i].back())) {
                prefix[i + 1] = prefix[i] + 1;
            } else {
                prefix[i + 1] = prefix[i];
            }
        }

        vector<int> result;
        for (auto& query : queries) {
            int l = query[0], r = query[1];
            result.push_back(prefix[r + 1] - prefix[l]);
        }

        return result;
    }
};