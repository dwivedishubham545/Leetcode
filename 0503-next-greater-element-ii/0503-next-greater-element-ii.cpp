class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;
        
        // Iterate through the array twice
        for (int i = 0; i < 2 * n; ++i) {
            int num = nums[i % n];
            
            // While stack is not empty and the current element is greater than the top of the stack
            while (!st.empty() && nums[st.top()] < num) {
                result[st.top()] = num;
                st.pop();
            }
            
            // Push index of current element onto the stack if we are in the first pass
            if (i < n) {
                st.push(i);
            }
        }
        
        return result;
    }
};