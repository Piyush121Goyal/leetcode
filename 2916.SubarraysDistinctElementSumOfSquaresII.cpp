class Solution {
    static const long long MOD = 1000000007LL;
    int n;
    vector<long long> sum, lazy;

    void push(int node, int l, int r) {
        if (lazy[node]) {
            int m = (l + r) / 2;
            apply(node * 2, l, m, lazy[node]);
            apply(node * 2 + 1, m + 1, r, lazy[node]);
            lazy[node] = 0;
        }
    }
    void apply(int node, int l, int r, long long v) {
        sum[node] += v * (r - l + 1);
        lazy[node] += v;
    }
    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) { apply(node, l, r, 1); return; }
        push(node, l, r);
        int m = (l + r) / 2;
        update(node * 2, l, m, ql, qr);
        update(node * 2 + 1, m + 1, r, ql, qr);
        sum[node] = sum[node * 2] + sum[node * 2 + 1];
    }
    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return sum[node];
        push(node, l, r);
        int m = (l + r) / 2;
        return query(node * 2, l, m, ql, qr) + query(node * 2 + 1, m + 1, r, ql, qr);
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sum.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        unordered_map<int, int> last;
        long long cur = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int p = last.count(nums[i]) ? last[nums[i]] : -1;
            long long s = query(1, 0, n - 1, p + 1, i);
            cur = (cur + 2 * (s % MOD) + (i - p)) % MOD;
            update(1, 0, n - 1, p + 1, i);
            ans = (ans + cur) % MOD;
            last[nums[i]] = i;
        }
        return (int)ans;
    }
};
