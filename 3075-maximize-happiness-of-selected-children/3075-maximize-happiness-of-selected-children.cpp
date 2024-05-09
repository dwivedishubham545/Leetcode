class Solution {
public:
    long long maximumHappinessSum(vector<int>& happi, int k) {
        priority_queue<long long, vector<long long>, less<long long>> heap;
        for (int h : happi) {
            heap.push(h);
        }

        long long totalHappi = 0;
        long long cumulativeDecrease = 0;

        while (k-- > 0 && !heap.empty()) {
            int currentHappi = heap.top();
            heap.pop();
            currentHappi -= cumulativeDecrease;
            totalHappi += max(0, currentHappi);
            if (currentHappi > 0) {
                cumulativeDecrease++;
            }
        }
        return totalHappi;
    }
};