class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
        vector<pair<int,int>> st;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] <= 0) continue;
                long long sum = 0;
                st.push_back({i, j});
                sum += grid[i][j];
                grid[i][j] = 0;
                while (!st.empty()) {
                    auto [r, c] = st.back(); st.pop_back();
                    for (int d = 0; d < 4; ++d) {
                        int nr = r + dr[d], nc = c + dc[d];
                        if (nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] <= 0) continue;
                        sum += grid[nr][nc];
                        grid[nr][nc] = 0;
                        st.push_back({nr, nc});
                    }
                }
                if (sum % k == 0) ++ans;
            }
        }
        return ans;
    }
};
