class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirs[5] = {0, 1, 0, -1, 0};

        // Flood-fill a land component starting at (r, c), turning it into water.
        // Returns true if the component never touches the border.
        auto fill = [&](int r, int c) {
            bool closed = true;
            vector<pair<int, int>> st;
            st.push_back({r, c});
            grid[r][c] = 1;
            while (!st.empty()) {
                auto [x, y] = st.back();
                st.pop_back();
                if (x == 0 || y == 0 || x == m - 1 || y == n - 1) closed = false;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dirs[d], ny = y + dirs[d + 1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        st.push_back({nx, ny});
                    }
                }
            }
            return closed;
        };

        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0 && fill(i, j)) count++;
        return count;
    }
};
