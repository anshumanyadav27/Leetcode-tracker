#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Pair value with original index: {nums[i], i}
        vector<pair<int, int>> paired(n);
        for (int i = 0; i < n; ++i) {
            paired[i] = {nums[i], i};
        }
        
        // Sort pairs primarily by value
        sort(paired.begin(), paired.end());
        
        vector<int> res(n);
        int i = 0;
        
        while (i < n) {
            int j = i + 1;
            
            // Find all contiguous elements that belong to the same component
            while (j < n && paired[j].first - paired[j - 1].first <= limit) {
                j++;
            }
            
            // Extract original indices for this component
            vector<int> indices;
            indices.reserve(j - i);
            for (int k = i; k < j; ++k) {
                indices.push_back(paired[k].second);
            }
            
            // Sort indices to place smallest values in the earliest positions
            sort(indices.begin(), indices.end());
            
            // Assign sorted values back to the sorted positions
            for (int k = i; k < j; ++k) {
                res[indices[k - i]] = paired[k].first;
            }
            
            i = j; // Move to next component
        }
        
        return res;
    }
};