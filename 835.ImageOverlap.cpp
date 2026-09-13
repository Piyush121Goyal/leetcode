class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> onesA, onesB;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) onesA.push_back({i, j});
                if (img2[i][j] == 1) onesB.push_back({i, j});
            }
        }
        int size = 2 * n + 1;
        vector<vector<int>> cnt(size, vector<int>(size, 0));
        int best = 0;
        for (auto& a : onesA) {
            for (auto& b : onesB) {
                int dx = b.first - a.first + n;
                int dy = b.second - a.second + n;
                cnt[dx][dy]++;
                best = max(best, cnt[dx][dy]);
            }
        }
        return best;
        //This is the personal solution changes 
    }
};
