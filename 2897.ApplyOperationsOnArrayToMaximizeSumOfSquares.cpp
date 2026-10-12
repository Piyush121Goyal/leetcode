class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        int cnt[31] = {0};
        for (int x : nums)
            for (int b = 0; b < 31; b++)
                if (x >> b & 1) cnt[b]++;
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            long long v = 0;
            for (int b = 0; b < 31; b++)
                if (cnt[b] > 0) { v |= 1LL << b; cnt[b]--; }
            v %= MOD;
            ans = (ans + v * v) % MOD;
        }
        return (int)ans;
    }
};
