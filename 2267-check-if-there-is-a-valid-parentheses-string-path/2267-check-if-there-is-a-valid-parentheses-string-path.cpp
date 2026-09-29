class Solution {
public:
    bool solve(vector<vector<char>>& grid, int i, int j, int balance,
               vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        // Process current cell
        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        // IMPORTANT: check before using balance as index
        if (balance < 0)
            return false;

        // Destination
        if (i == m - 1 && j == n - 1)
            return balance == 0;

        // Already calculated
        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool ans = false;

        // Move down
        if (i + 1 < m) {
            ans = ans || solve(grid, i + 1, j, balance, dp);
        }

        // Move right
        if (j + 1 < n) {
            ans = ans || solve(grid, i, j + 1, balance, dp);
        }

        return dp[i][j][balance] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n + 1, -1)
            )
        );

        return solve(grid, 0, 0, 0, dp);
    }
};