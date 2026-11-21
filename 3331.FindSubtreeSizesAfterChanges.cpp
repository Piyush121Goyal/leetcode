class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);

        vector<int> newParent(parent), order, last(26, -1), saved(n, -1);
        order.reserve(n);

        // Iterative DFS: track the closest ancestor for each character.
        vector<pair<int, int>> st;
        st.push_back({0, 0});
        while (!st.empty()) {
            int u = st.back().first;
            int& idx = st.back().second;
            int c = s[u] - 'a';
            if (idx == 0) {
                order.push_back(u);
                if (u != 0 && last[c] != -1) newParent[u] = last[c];
                saved[u] = last[c];
                last[c] = u;
            }
            if (idx < (int)children[u].size()) {
                int v = children[u][idx++];
                st.push_back({v, 0});
            } else {
                last[c] = saved[u];
                st.pop_back();
            }
        }

        // New parents are original ancestors, so reverse preorder accumulates sizes correctly.
        vector<int> ans(n, 1);
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            ans[newParent[u]] += ans[u];
        }
        return ans;
    }
};
