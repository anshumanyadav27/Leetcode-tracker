#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }

        // Check if a palindromic permutation is possible
        int odd_count = 0;
        char mid_char = 0;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
        }
        if (odd_count > 1) {
            return "";
        }

        // Frequencies for the first half
        vector<int> half_counts(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_counts[i] = counts[i] / 2;
        }

        int half_len = n / 2;
        string best_pal = "";

        // Helper lambda to form a palindrome from the first half
        auto build_palindrome = [&](const string& half_str) {
            string rev = half_str;
            reverse(rev.begin(), rev.end());
            if (n % 2 != 0) {
                return half_str + mid_char + rev;
            }
            return half_str + rev;
        };

        string curr_prefix = "";
        vector<int> curr_counts = half_counts;

        for (int i = 0; i <= half_len; ++i) {
            if (i < half_len) {
                char t_char = target[i];

                // Try placing a character c > target[i] at position i
                for (int c_idx = (t_char - 'a') + 1; c_idx < 26; ++c_idx) {
                    if (curr_counts[c_idx] > 0) {
                        vector<int> rem_counts = curr_counts;
                        rem_counts[c_idx]--;

                        string candidate_half = curr_prefix + (char)('a' + c_idx);
                        for (int ch = 0; ch < 26; ++ch) {
                            candidate_half.append(rem_counts[ch], 'a' + ch);
                        }

                        string candidate_pal = build_palindrome(candidate_half);
                        if (best_pal.empty() || candidate_pal < best_pal) {
                            best_pal = candidate_pal;
                        }
                    }
                }

                // Match target[i] to continue building the prefix
                int t_idx = t_char - 'a';
                if (curr_counts[t_idx] > 0) {
                    curr_prefix += t_char;
                    curr_counts[t_idx]--;
                } else {
                    // Cannot match target[i] anymore
                    break;
                }
            } else {
                // i == half_len: exact match on the first half
                string candidate_pal = build_palindrome(curr_prefix);
                if (candidate_pal > target) {
                    if (best_pal.empty() || candidate_pal < best_pal) {
                        best_pal = candidate_pal;
                    }
                }
            }
        }

        return best_pal;
    }
};