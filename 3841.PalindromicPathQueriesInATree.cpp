class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        vector<vector<int>> up(LOG + 1, vector<int>(n, 0));
        vector<int> depth(n, 0), tin(n), tout(n);
        // iterative DFS for Euler tour
        vector<int> st = {0}, it(n, 0);
        vector<char> vis(n, 0);
        vis[0] = 1;
        int timer = 0;
        tin[0] = timer++;
        while (!st.empty()) {
            int u = st.back();
            if (it[u] < (int)adj[u].size()) {
                int v = adj[u][it[u]++];
                if (vis[v]) continue;
                vis[v] = 1;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                tin[v] = timer++;
                st.push_back(v);
            } else {
                tout[u] = timer - 1;
                st.pop_back();
            }
        }
        for (int k = 1; k <= LOG; k++)
            for (int v = 0; v < n; v++)
                up[k][v] = up[k - 1][up[k - 1][v]];
        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);
            int diff = depth[a] - depth[b];
            for (int k = 0; k <= LOG; k++)
                if (diff >> k & 1) a = up[k][a];
            if (a == b) return a;
            for (int k = LOG; k >= 0; k--)
                if (up[k][a] != up[k][b]) { a = up[k][a]; b = up[k][b]; }
            return up[0][a];
        };
        // Fenwick tree over Euler positions: range XOR update, point query
        vector<int> bit(n + 2, 0);
        auto add = [&](int i, int val) {
            for (i++; i <= n + 1; i += i & -i) bit[i] ^= val;
        };
        auto query = [&](int i) {
            int r = 0;
            for (i++; i > 0; i -= i & -i) r ^= bit[i];
            return r;
        };
        auto applyNode = [&](int v, int mask) {
            // XOR mask onto root-to-x prefix for every x in subtree of v
            add(tin[v], mask);
            add(tout[v] + 1, mask);
        };
        vector<int> mask(n);
        for (int i = 0; i < n; i++) {
            mask[i] = 1 << (s[i] - 'a');
            applyNode(i, mask[i]);
        }
        vector<bool> ans;
        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u; char c;
                ss >> u >> c;
                int nm = 1 << (c - 'a');
                if (nm != mask[u]) {
                    applyNode(u, mask[u] ^ nm);
                    mask[u] = nm;
                }
            } else {
                int u, v;
                ss >> u >> v;
                int w = lca(u, v);
                int m = query(tin[u]) ^ query(tin[v]) ^ mask[w];
                ans.push_back((m & (m - 1)) == 0);
            }
        }
        return ans;
    }
};
