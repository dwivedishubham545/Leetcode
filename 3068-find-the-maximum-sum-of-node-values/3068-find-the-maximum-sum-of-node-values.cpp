class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int nodeCount = nums.size();
        vector<int> adjacencyList[nodeCount];
        for(int edgeIndex = 0; edgeIndex < nodeCount - 1; edgeIndex++)
        {
            adjacencyList[edges[edgeIndex][0]].push_back(edges[edgeIndex][1]);
            adjacencyList[edges[edgeIndex][1]].push_back(edges[edgeIndex][0]);
        }
        vector<int> nodesToIncrease;
        for(int nodeIndex = 0; nodeIndex < nodeCount; nodeIndex++)
        {
            long long newValue = static_cast<long long>(nums[nodeIndex]) ^ k;
            if(newValue > nums[nodeIndex])
            {
                nodesToIncrease.push_back(nodeIndex);
            }
        }
        int increaseSize = nodesToIncrease.size();
        if(increaseSize % 2 == 0)
        {
            long long totalSum = 0;
            for(int nodeIndex = 0; nodeIndex < nodeCount; nodeIndex++)
            {
                totalSum += nums[nodeIndex];
            }
            for(int increasedNode : nodesToIncrease)
            {
                totalSum -= nums[increasedNode];
                long long increasedValue = static_cast<long long>(nums[increasedNode]) ^ k;
                totalSum += increasedValue;
            }
            return totalSum;
        }
        else
        {
            long long initialSum = 0;
            for(int nodeIndex = 0; nodeIndex < nodeCount; nodeIndex++)
            {
                initialSum += static_cast<long long>(nums[nodeIndex]);
            }
            long long maxSum = initialSum;
            
            for(int increasedNode : nodesToIncrease)
            {
                initialSum -= nums[increasedNode];
                long long increasedValue = static_cast<long long>(nums[increasedNode]) ^ k;
                initialSum += increasedValue;
            }
            for(int increasedNode : nodesToIncrease)
            {
                long long decreasedValue = static_cast<long long>(nums[increasedNode]) ^ k;
                long long alternativeSum = initialSum - decreasedValue + nums[increasedNode];
                maxSum = max(maxSum, alternativeSum);
            }
            
            vector<int> visitedNodes(nodeCount, 0);
            for(int increasedNode : nodesToIncrease)
            {
                visitedNodes[increasedNode] = 1;
            }
            for(int nodeIndex = 0; nodeIndex < nodeCount; nodeIndex++)
            {
                if(!visitedNodes[nodeIndex])
                {
                    long long increasedValue = static_cast<long long>(nums[nodeIndex]) ^ k;
                    long long alternativeSum = initialSum - nums[nodeIndex] + increasedValue;
                    maxSum = max(maxSum, alternativeSum);
                }
            }
            return maxSum;
        }
    }
};
