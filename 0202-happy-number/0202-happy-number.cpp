class Solution {
public:
    bool isHappy(int n) {
         while(n>9)
        {
            int f=n;n=0;
            while(f!=0)
            {
                n=n+(f%10)*(f%10);
                f/=10;
            }
        }
        return n==1||n==7;
    }
};