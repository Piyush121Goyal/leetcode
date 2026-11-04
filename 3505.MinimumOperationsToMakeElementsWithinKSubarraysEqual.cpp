class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        // cost[i]: operations to make the window starting at i all equal (to its median)
        vector<long long> cost(n - x + 1);
        multiset<int> low, high;   // low holds the smaller half (its max is the median)
        long long sumLow = 0, sumHigh = 0;

        auto rebalance = [&]() {
            while (low.size() > high.size() + 1) {
                auto it = prev(low.end());
                sumLow -= *it;
                sumHigh += *it;
                high.insert(*it);
                low.erase(it);
            }
            while (low.size() < high.size()) {
                auto it = high.begin();
                sumHigh -= *it;
                sumLow += *it;
                low.insert(*it);
                high.erase(it);
            }
        };

        for (int i = 0; i < n; i++) {
            if (low.empty() || nums[i] <= *low.rbegin()) {
                low.insert(nums[i]);
                sumLow += nums[i];
            } else {
                high.insert(nums[i]);
                sumHigh += nums[i];
            }
            if (i >= x) {
                int out = nums[i - x];
                auto it = low.find(out);
                if (it != low.end()) {
                    low.erase(it);
                    sumLow -= out;
                } else {
                    high.erase(high.find(out));
                    sumHigh -= out;
                }
            }
            rebalance();
            if (i >= x - 1) {
                long long med = *low.rbegin();
                cost[i - x + 1] = med * (long long)low.size() - sumLow
                                + sumHigh - med * (long long)high.size();
            }
        }

        // dp[i]: min cost using the first i elements with the current number of subarrays
        const long long INF = LLONG_MAX / 2;
        vector<long long> dp(n + 1, 0);
        for (int j = 1; j <= k; j++) {
            vector<long long> next(n + 1, INF);
            for (int i = x; i <= n; i++) {
                next[i] = next[i - 1];
                if (dp[i - x] < INF) {
                    next[i] = min(next[i], dp[i - x] + cost[i - x]);
                }
            }
            dp = move(next);
        }
        return dp[n];
    }
};
