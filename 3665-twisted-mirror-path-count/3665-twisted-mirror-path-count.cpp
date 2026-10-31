
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int mod = 1e9 + 7;

        vector<vector<long long>> right(m, vector<long long>(n, 0));
        vector<vector<long long>> down(m, vector<long long>(n, 0));

        right[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                long long r = right[i][j];
                long long d = down[i][j];

                if (grid[i][j] == 0) {
                    long long ways = (r + d) % mod;

                    if (i == 0 && j == 0)
                        ways = 1;

                    // Move right
                    if (j + 1 < n) {
                        right[i][j + 1] =
                            (right[i][j + 1] + ways) % mod;
                    }

                    // Move down
                    if (i + 1 < m) {
                        down[i + 1][j] =
                            (down[i + 1][j] + ways) % mod;
                    }
                }
                else {
                    // Mirror: entered while moving right
                    // Reflect downward
                    if (r > 0 && i + 1 < m) {
                        down[i + 1][j] =
                            (down[i + 1][j] + r) % mod;
                    }

                    // Mirror: entered while moving down
                    // Reflect rightward
                    if (d > 0 && j + 1 < n) {
                        right[i][j + 1] =
                            (right[i][j + 1] + d) % mod;
                    }
                }
            }
        }

        return (right[m - 1][n - 1] +
                down[m - 1][n - 1]) % mod;
    }
};
