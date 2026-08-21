class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int c;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            c=nums[n-k];
        }
        return c;
    }
};