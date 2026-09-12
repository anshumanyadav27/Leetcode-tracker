#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct Interval {
        int l, r, weight, id;
    };

    struct DPState {
        long long max_weight = 0;
        vector<int> indices;

        // Custom comparator for maximum weight and lexicographically smallest indices
        bool isBetterThan(const DPState& other) const {
            if (max_weight != other.max_weight) {
                return max_weight > other.max_weight;
            }
            return indices < other.indices;
        }
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort intervals by start time
        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            return a.l < b.l;
        });

        // Next non-overlapping interval lookup table using Binary Search
        vector<int> next_idx(n);
        for (int i = 0; i < n; ++i) {
            int low = i + 1, high = n, ans = n;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (arr[mid].l > arr[i].r) { // Strict non-overlapping condition
                    ans = mid;
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            next_idx[i] = ans;
        }

        // dp[i][k] = Best state considering intervals from index i to n-1 selecting at most k intervals
        vector<vector<DPState>> dp(n + 1, vector<DPState>(5));

        for (int i = n - 1; i >= 0; --i) {
            for (int k = 1; k <= 4; ++k) {
                // Option 1: Skip current interval
                DPState best = dp[i + 1][k];

                // Option 2: Pick current interval
                int nxt = next_idx[i];
                DPState take;
                take.max_weight = arr[i].weight + dp[nxt][k - 1].max_weight;
                
                take.indices.push_back(arr[i].id);
                for (int idx : dp[nxt][k - 1].indices) {
                    take.indices.push_back(idx);
                }
                sort(take.indices.begin(), take.indices.end());

                if (take.isBetterThan(best)) {
                    best = take;
                }

                dp[i][k] = best;
            }
        }

        return dp[0][4].indices;
    }
};