class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        vector<int> a;
        for(int i=0; i<nums.size(); i++){
            ans.push_back(nums[i]);
        }
        for(int i=0; i<nums.size(); i++){
            a.push_back(nums[i]);
        }
        for(int i=0; i<a.size(); i++){
            ans.push_back(a[i]);
        }
        return ans;
    }
};