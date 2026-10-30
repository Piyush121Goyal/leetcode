class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});
        const long long INF = LLONG_MAX;
        // dist[node * (k + 1) + cnt]: min weight reaching node with a run of cnt identical labels ending there
        vector<long long> dist((long long)n * (k + 1), INF);
        priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<>> pq;
        dist[0 * (k + 1) + 1] = 0;
        pq.push({0, 0, 1});
        while (!pq.empty()) {
            auto [d, u, c] = pq.top(); pq.pop();
            if (d != dist[(long long)u * (k + 1) + c]) continue;
            if (u == n - 1) return (int)d;
            for (auto& [v, w] : adj[u]) {
                int nc = (labels[u] == labels[v]) ? c + 1 : 1;
                if (nc > k) continue;
                long long nd = d + w;
                long long idx = (long long)v * (k + 1) + nc;
                if (nd < dist[idx]) {
                    dist[idx] = nd;
                    pq.push({nd, v, nc});
                }
            }
        }
        return -1;
    }
};
