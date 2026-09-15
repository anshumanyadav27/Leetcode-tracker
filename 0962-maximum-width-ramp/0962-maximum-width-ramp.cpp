class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int max_width = 0;

        stack<int> st;

        // Store indices with decreasing values
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        // Traverse from right to left
        for (int j = n - 1; j >= 0; j--) {
            while (!st.empty() && nums[st.top()] <= nums[j]) {
                max_width = max(max_width, j - st.top());
                st.pop();
            }
        }

        return max_width;
    }
};