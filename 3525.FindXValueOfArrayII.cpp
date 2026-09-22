class Solution {
public:
    static const int MAXK = 5;
    struct Node {
        int M[MAXK][MAXK];
        int T[MAXK];
    };
    int k;
    int n;
    vector<Node> tree;

    Node makeLeaf(long long v) {
        Node nd;
        long long vm = v % K;
        for (int a = 0; a < K; a++) {
            int b = (int)((a * vm) % K);
            nd.T[a] = b;
            for (int bb = 0; bb < K; bb++) nd.M[a][bb] = (bb == b) ? 1 : 0;
        }
        return nd;
    }

    Node identityNode() {
        Node nd;
        for (int a = 0; a < K; a++) {
            nd.T[a] = a;
            for (int b = 0; b < K; b++) nd.M[a][b] = 0;
        }
        return nd;
    }

    Node combine(const Node& L, const Node& R) {
        Node res;
        for (int a = 0; a < K; a++) {
            int mid = L.T[a];
            res.T[a] = R.T[mid];
            for (int b = 0; b < K; b++) {
                res.M[a][b] = L.M[a][b] + R.M[mid][b];
            }
        }
        return res;
    }

    void build(int idx, int l, int r, vector<int>& arr) {
        if (l == r) { tree[idx] = makeLeaf(arr[l]); return; }
        int mid = (l + r) / 2;
        build(idx * 2, l, mid, arr);
        build(idx * 2 + 1, mid + 1, r, arr);
        tree[idx] = combine(tree[idx * 2], tree[idx * 2 + 1]);
    }

    void update(int idx, int l, int r, int pos, long long val) {
        if (l == r) { tree[idx] = makeLeaf(val); return; }
        int mid = (l + r) / 2;
        if (pos <= mid) update(idx * 2, l, mid, pos, val);
        else update(idx * 2 + 1, mid + 1, r, pos, val);
        tree[idx] = combine(tree[idx * 2], tree[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return identityNode();
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) / 2;
        Node lft = query(idx * 2, l, mid, ql, qr);
        Node rgt = query(idx * 2 + 1, mid + 1, r, ql, qr);
        return combine(lft, rgt);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        K = k;
        n = nums.size();
        tree.assign(4 * n, Node());
        build(1, 0, n - 1, nums);
        vector<int> ans;
        ans.reserve(queries.size());
        int startRem = 1 % K;
        for (auto& q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            update(1, 0, n - 1, index, (long long)value);
            Node r = query(1, 0, n - 1, start, n - 1);
            ans.push_back(r.M[startRem][x]);
        }
        return ans;
    }
};
