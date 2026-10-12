class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0), dp(k, 0);
        for (int v : nums) {
            vector<long long> nd(k, 0);
            int m = v % k;
            nd[m % k]++;
            for (int r = 0; r < k; r++) nd[(r * m) % k] += dp[r];
            dp = nd;
            for (int r = 0; r < k; r++) result[r] += dp[r];
        }
        return result;
    }
};
