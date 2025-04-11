class Solution {
private:
    bool isSymmetric(int num){
        string s = to_string(num);
        if(s.length() % 2 != 0){
            return false;
        }
        int n = s.length() / 2;
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++){
            sum1 += s[i] - '0'; 
        }
        for(int i = n; i < s.length(); i++){
            sum2 += s[i] - '0';
        }
        return sum1 == sum2;
    }

public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++){
            if(isSymmetric(i)){
                cnt++;
            }
        }
        return cnt;
    }
};
