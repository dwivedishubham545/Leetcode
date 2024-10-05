class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) return false;
        
        vector<int> s1_freq(26, 0), s2_freq(26, 0);
        
        for (int i = 0; i < m; i++) {
            s1_freq[s1[i] - 'a']++;
            s2_freq[s2[i] - 'a']++;
        }
        
        for (int i = m; i < n; i++) {
            if (s1_freq == s2_freq) return true; 
            
            s2_freq[s2[i] - 'a']++;
            s2_freq[s2[i - m] - 'a']--;
        }
        
        return s1_freq == s2_freq;
    }
};
