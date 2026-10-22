class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> rev(nums.rbegin(), nums.rend());
        // target states: (t, s) where rotating B_t left by s gives sorted order
        vector<int> target(2 * n, 0);
        auto check = [&](const vector<int>& b, int t) {
            int s = -1;
            for (int i = 0; i < n; i++) if (b[i] == 0) { s = i; break; }
            for (int i = 0; i < n; i++)
                if (b[(s + i) % n] != i) return;
            target[t * n + s] = 1;
        };
        check(nums, 0);
        check(rev, 1);
        vector<int> dist(2 * n, -1);
        queue<int> q;
        dist[0] = 0; q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (target[u]) return dist[u];
            int t = u / n, s = u % n;
            int v1 = t * n + (s + 1) % n;
            int v2 = (1 - t) * n + (n - s) % n;
            for (int v : {v1, v2})
                if (dist[v] == -1) { dist[v] = dist[u] + 1; q.push(v); }
        }
        return -1;
    }
};
