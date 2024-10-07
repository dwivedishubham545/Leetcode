class Solution {
public:
    int minLength(string s) {
        int n = s.length();
        int j = 0;

        for (int i = 0; i < n; ++i) {
            s[j] = s[i]; 
            
            if (j > 0 && ((s[j - 1] == 'A' && s[j] == 'B') || (s[j - 1] == 'C' && s[j] == 'D'))) {
                j -= 2; 
            }
            ++j; 
        }

        return j;
    }
};