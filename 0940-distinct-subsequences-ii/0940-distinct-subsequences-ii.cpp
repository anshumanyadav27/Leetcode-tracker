#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int distinctSubseqII(std::string s) {
        int n = s.length();
        long long MOD = 1e9 + 7;
        
        // dp[i] stores distinct subsequences using s[0...i-1] including empty string
        std::vector<long long> dp(n + 1, 0);
        dp[0] = 1; // Empty subsequence
        
        // Stores the last seen dp state index for each character 'a'-'z'
        std::vector<int> last(26, -1);
        
        for (int i = 1; i <= n; ++i) {
            char ch = s[i - 1];
            
            // Double the number of subsequences by attaching current character
            dp[i] = (2 * dp[i - 1]) % MOD;
            
            // If the character appeared before, subtract duplicate subsequences
            if (last[ch - 'a'] != -1) {
                int prev_dp_index = last[ch - 'a'];
                dp[i] = (dp[i] - dp[prev_dp_index] + MOD) % MOD;
            }
            
            // Update last seen position for character s[i-1]
            last[ch - 'a'] = i - 1;
        }
        
        // Exclude the empty string
        return (dp[n] - 1 + MOD) % MOD;
    }
};