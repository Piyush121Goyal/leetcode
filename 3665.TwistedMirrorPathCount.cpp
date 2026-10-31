class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        // dp[i][j][d]: ways to arrive at (i,j) while moving in direction d (0 = right, 1 = down)
        vector<vector<array<long long, 2>>> dp(m, vector<array<long long, 2>>(n, {0, 0}));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // moving right into a mirror -> deflected down
                    if (i + 1 < m) dp[i + 1][j][1] = (dp[i + 1][j][1] + dp[i][j][0]) % MOD;
                    // moving down into a mirror -> deflected right
                    if (j + 1 < n) dp[i][j + 1][0] = (dp[i][j + 1][0] + dp[i][j][1]) % MOD;
                } else {
                    long long ways = (i == 0 && j == 0) ? 1 : (dp[i][j][0] + dp[i][j][1]) % MOD;
                    if (j + 1 < n) dp[i][j + 1][0] = (dp[i][j + 1][0] + ways) % MOD;
                    if (i + 1 < m) dp[i + 1][j][1] = (dp[i + 1][j][1] + ways) % MOD;
                }
            }
        }
        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
    }
};
