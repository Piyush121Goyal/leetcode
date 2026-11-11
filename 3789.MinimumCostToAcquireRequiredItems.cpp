class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long common = min(need1, need2);
        long long rem1 = need1 - common, rem2 = need2 - common;
        return common * min(cb, c1 + c2) + rem1 * min(cb, c1) + rem2 * min(cb, c2);
    }
};
