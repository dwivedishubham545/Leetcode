#include <vector>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();

        if (len2 % 2 == 1) {
            for (int num1 : nums1) {
                ans ^= num1;
            }
        }

        if (len1 % 2 == 1) {
            for (int num2 : nums2) {
                ans ^= num2;
            }
        }

        return ans;
    }
};