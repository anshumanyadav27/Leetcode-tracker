class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        for (int i = 1; i <= nums.size() + 1; i++) {
            
            int multiple = k * i;
            bool found = false;
            
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == multiple) {
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                return multiple;
            }
        }
        
        return 0;
    }
};