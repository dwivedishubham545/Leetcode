class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;
        
        // Traverse the nums2 array from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            
            // Maintain the stack such that elements are in decreasing order from bottom to top
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }
            
            // If stack is empty, it means there's no greater element to the right
            nextGreater[num] = st.empty() ? -1 : st.top();
            
            // Push the current number onto the stack
            st.push(num);
        }
        
        // Prepare the result array based on nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }
        
        return result;
    }
};