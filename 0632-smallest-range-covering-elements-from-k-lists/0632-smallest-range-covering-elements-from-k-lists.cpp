class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        
        int currentMax = INT_MIN;  
        int rangeStart = 0, rangeEnd = INT_MAX;  

        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], i, 0});  
            currentMax = max(currentMax, nums[i][0]); 
        }

        while (!minHeap.empty()) {
            auto [minVal, listIdx, idxInList] = minHeap.top();
            minHeap.pop();

            if (currentMax - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = currentMax;
            }

            if (idxInList + 1 < nums[listIdx].size()) {
                int nextVal = nums[listIdx][idxInList + 1];
                minHeap.push({nextVal, listIdx, idxInList + 1});
                currentMax = max(currentMax, nextVal); 
            } else {
                break;
            }
        }

        return {rangeStart, rangeEnd};
    }
};
