class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for (char x : s) {
            int num = x - 'a' + 1;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
        }
        
        while (k > 1) {
            int tempSum = 0;
            while (sum > 0) {
                tempSum += sum % 10;
                sum /= 10;
            }
            sum = tempSum;
            k--;
        }
        
        return sum;
    }
};
