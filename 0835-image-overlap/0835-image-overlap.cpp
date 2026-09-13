#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
        int n = img1.size();
        std::vector<std::pair<int, int>> A, B;

        // Step 1: Record coordinates of all 1s in both images
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) A.push_back({r, c});
                if (img2[r][c] == 1) B.push_back({r, c});
            }
        }

        // Step 2: Map to store the frequency of each shift vector (dr, dc)
        std::map<std::pair<int, int>, int> count;
        int max_overlap = 0;

        // Step 3: Calculate translation vectors for every pair of 1s
        for (const auto& [r1, c1] : A) {
            for (const auto& [r2, c2] : B) {
                std::pair<int, int> shift = {r2 - r1, c2 - c1};
                count[shift]++;
                max_overlap = std::max(max_overlap, count[shift]);
            }
        }

        return max_overlap;
    }
};