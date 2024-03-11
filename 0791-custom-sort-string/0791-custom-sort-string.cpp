class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        string result = "";
        for (char c : order) {
            if (charCount.find(c) != charCount.end()) {
                result += string(charCount[c], c);
                charCount.erase(c);
            }
        }
        for (auto& pair : charCount) {
            result += string(pair.second, pair.first); 
        }

        return result;
    }
};