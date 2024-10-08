class Solution {
public:
    int minSwaps(string s) {
        int open = 0, close = 0;  
        for (char ch : s) {
            if (ch == '[') {
                open++;  
            } else {
                if (open > 0) {
                    open--;
                } else {
                    close++; 
                }
            }
        }
        return (close + 1) / 2;
    }
};
