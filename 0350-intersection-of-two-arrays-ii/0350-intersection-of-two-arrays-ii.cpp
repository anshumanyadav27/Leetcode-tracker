class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int n = nums1.size();
        int k = nums2.size();

        if (n <= k) {
            vector<int> visited(k, 0);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < k; j++) {
                    if (nums1[i] == nums2[j] && visited[j] == 0) {
                        nums3.push_back(nums1[i]);
                        visited[j] = 1;
                        break;
                    }
                }
            }
        } else {
            vector<int> visited(n, 0);

            for (int i = 0; i < k; i++) {
                for (int j = 0; j < n; j++) {
                    if (nums2[i] == nums1[j] && visited[j] == 0) {
                        nums3.push_back(nums2[i]);
                        visited[j] = 1;
                        break;
                    }
                }
            }
        }

        return nums3;
    }
};