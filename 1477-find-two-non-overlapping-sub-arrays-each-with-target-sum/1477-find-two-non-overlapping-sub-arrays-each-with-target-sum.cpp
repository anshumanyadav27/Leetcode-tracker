class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n + 1, INF);

        int left = 0;
        int sum = 0;
        int answer = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Carry forward the minimum length found so far
            best[right + 1] = best[right];

            if (sum == target) {
                int length = right - left + 1;

                // best[left] contains a previous non-overlapping subarray
                if (best[left] != INF) {
                    answer = min(answer, best[left] + length);
                }

                // Store the shortest subarray ending at or before right
                best[right + 1] = min(best[right + 1], length);
            }
        }

        if (answer == INF) {
            return -1;
        }

        return answer;
    }
};