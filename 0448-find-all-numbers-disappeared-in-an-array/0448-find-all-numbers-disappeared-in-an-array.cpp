class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        sort(nums.begin(), nums.end());

        int j = 0;

        for(int i = 1; i <= nums.size(); i++) {

            while(j < nums.size() && nums[j] < i) {
                j++;
            }

            if(j < nums.size() && nums[j] == i) {
                continue;
            }
            else {
                ans.push_back(i);
            }
        }

        return ans;
    }
};