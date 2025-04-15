class Solution {
public:
    typedef long long ll;

    class BIT {
    public:
        vector<int> bit;
        int size;
        BIT(int n) : size(n + 2) {
            bit.resize(size, 0);
        }
        void update(int i, int val) {
            for (++i; i < size; i += i & -i)
                bit[i] += val;
        }
        int query(int i) {
            int res = 0;
            for (++i; i > 0; i -= i & -i)
                res += bit[i];
            return res;
        }
    };

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i)
            pos[nums2[i]] = i;

        vector<int> mapped(n);
        for (int i = 0; i < n; ++i)
            mapped[i] = pos[nums1[i]];

        vector<int> leftCount(n), rightCount(n);

        BIT bitLeft(n), bitRight(n);
        for (int i = 0; i < n; ++i) {
            leftCount[i] = bitLeft.query(mapped[i] - 1);
            bitLeft.update(mapped[i], 1);
        }

        for (int i = n - 1; i >= 0; --i) {
            rightCount[i] = bitRight.query(n - 1) - bitRight.query(mapped[i]);
            bitRight.update(mapped[i], 1);
        }

        ll total = 0;
        for (int i = 0; i < n; ++i) {
            total += (ll)leftCount[i] * rightCount[i];
        }

        return total;
    }
};
