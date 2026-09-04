#include <vector>
#include <algorithm>

class Solution {
public:
    int firstStableIndex(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // suf_min[i] stores the minimum value from index i to n - 1
        std::vector<int> suf_min(n);
        suf_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suf_min[i] = std::min(suf_min[i + 1], nums[i]);
        }
        
        int pref_max = nums[0];
        for (int i = 0; i < n; ++i) {
            pref_max = std::max(pref_max, nums[i]);
            
            // Instability score: max(nums[0..i]) - min(nums[i..n-1])
            long long instability = (long long)pref_max - suf_min[i];
            
            if (instability <= k) {
                return i;
            }
        }
        
        return -1;
    }
};