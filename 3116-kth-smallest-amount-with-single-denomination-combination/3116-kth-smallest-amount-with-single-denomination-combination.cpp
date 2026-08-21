#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        int n = coins.size();
        
        // Store precomputed (LCM of subset, sign)
        // sign is +1 for odd size subsets, -1 for even size subsets
        std::vector<std::pair<long long, int>> subsets;
        
        // Generate all non-empty subsets (2^n - 1)
        int numSubsets = 1 << n;
        for (int mask = 1; mask < numSubsets; ++mask) {
            long long currentLcm = 1;
            int bitsSet = 0;
            
            for (int j = 0; j < n; ++j) {
                if ((mask >> j) & 1) {
                    bitsSet++;
                    currentLcm = std::lcm(currentLcm, (long long)coins[j]);
                }
            }
            
            int sign = (bitsSet % 2 == 1) ? 1 : -1;
            subsets.push_back({currentLcm, sign});
        }
        
        // Count numbers <= x divisible by at least one coin denomination
        auto countMultiples = [&](long long x) -> long long {
            long long total = 0;
            for (const auto& [subLcm, sign] : subsets) {
                total += sign * (x / subLcm);
            }
            return total;
        };
        
        // Binary Search range
        long long low = *std::min_element(coins.begin(), coins.end());
        long long high = low * k;
        long long ans = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countMultiples(mid) >= k) {
                ans = mid;
                high = mid - 1; // Search left half for smallest valid value
            } else {
                low = mid + 1;  // Search right half
            }
        }
        
        return ans;
    }
};