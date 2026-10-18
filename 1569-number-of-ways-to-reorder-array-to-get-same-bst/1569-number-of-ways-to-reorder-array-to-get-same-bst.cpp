
class Solution {
public:
    long long mod = 1000000007;
    long long ways(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long ans = 1;

        // Calculate combinations C(n-1, left.size())
        long long comb = 1;
        int l = left.size();

        for (int i = 1; i <= l; i++) {
            comb = comb * (n - i) % mod;
            // modular inverse of i
            long long inv = 1;
            long long base = i, exp = mod - 2;

            while (exp > 0) {
                if (exp & 1)
                    inv = inv * base % mod;
                base = base * base % mod;
                exp >>= 1;
            }

            comb = comb * inv % mod;
        }

        ans = comb;
        ans = ans * ways(left) % mod;
        ans = ans * ways(right) % mod;

        return ans;
    }

    int numOfWays(vector<int>& nums) {
        return (ways(nums) - 1 + mod) % mod;
    }
};
