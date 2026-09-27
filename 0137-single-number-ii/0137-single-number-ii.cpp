class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            bool found = false;

            for(int j = 0; j < nums.size(); j++) {
                if(i != j && nums[i] == nums[j]) {
                    found = true;
                    break;
                }
            }

            if(found == false) {
                return nums[i];
            }
        }

        return -1;
    }
};