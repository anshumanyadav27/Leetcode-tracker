
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> c;

        for (int i = 0; i < nums.size(); i++) {
            c.push_back(abs(nums[i]));
        }

        sort(c.begin(), c.end());

        long long ans1 = 0, ans2 = 0;

        for (int i = 0; i < c.size() / 2; i++) {
            ans1 += 1LL * c[i] * c[i];
        }

        for (int i = c.size() / 2; i < c.size(); i++) {
            ans2 += 1LL * c[i] * c[i];
        }

        return ans2 - ans1;
    }
};
