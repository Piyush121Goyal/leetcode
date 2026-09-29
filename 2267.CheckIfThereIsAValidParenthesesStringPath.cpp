class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // Path length must be even, must start with '(' and end with ')'
        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        // dp[i][j] = set of reachable open-bracket balances at cell (i, j)
        vector<vector<bitset<205>>> dp(m, vector<bitset<205>>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bitset<205> prev;
                if (i == 0 && j == 0) {
                    prev[0] = 1;
                } else {
                    if (i > 0) prev |= dp[i - 1][j];
                    if (j > 0) prev |= dp[i][j - 1];
                }
                // '(' increases balance; ')' decreases it (balance 0 drops off, i.e. invalid)
                dp[i][j] = (grid[i][j] == '(') ? (prev << 1) : (prev >> 1);
            }
        }
        return dp[m - 1][n - 1][0];
    }
};
