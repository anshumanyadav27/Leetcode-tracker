class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool ok = true;
            int prevMax = -1;

            for (int start = 0; start < n; start += k) {
                int cnt = 0;
                int mn = nums[start];
                int mx = nums[start];

                for (int j = start; j < start + k; j++) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);

                    int next = (j + 1 == start + k)
                                   ? start
                                   : j + 1;

                    if (nums[j] > nums[next])
                        cnt++;
                }

                if (cnt > 1 || (start > 0 && prevMax > mn)) {
                    ok = false;
                    break;
                }

                prevMax = mx;
            }

            if (ok)
                ans += k;
        }

        return ans;
    }
};