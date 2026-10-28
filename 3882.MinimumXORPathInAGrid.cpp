class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // dp[i][j] = set of XOR values reachable at cell (i, j)
        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = grid[i][j];
                if (i == 0 && j == 0) { dp[0][0][v] = 1; continue; }
                bitset<1024> prev;
                if (i > 0) prev |= dp[i - 1][j];
                if (j > 0) prev |= dp[i][j - 1];
                for (int x = 0; x < 1024; x++)
                    if (prev[x]) dp[i][j][x ^ v] = 1;
            }
        }
        for (int x = 0; x < 1024; x++)
            if (dp[m - 1][n - 1][x]) return x;
        return 0;
    }
};
