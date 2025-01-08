class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        if (str1.length() > str2.length()) return false;
        bool isPrefix = str2.substr(0, str1.length()) == str1;
        bool isSuffix = str2.substr(str2.length() - str1.length()) == str1;
        return isPrefix && isSuffix;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
         int count = 0;
        for (size_t i = 0; i < words.size(); ++i) {
            for (size_t j = i + 1; j < words.size(); ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ++count;
                }
            }
        }
        return count;
    }
};