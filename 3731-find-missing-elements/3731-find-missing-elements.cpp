
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> ans;
        int j = 0;

        for (int i = nums[0]; i <= nums[n - 1]; i++) {
            if (j < n && nums[j] == i) {
                j++;
            } 
            else {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
