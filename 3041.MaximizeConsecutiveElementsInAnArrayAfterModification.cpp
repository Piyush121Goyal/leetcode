class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxVal = nums.back() + 2;
        vector<int> dp(maxVal + 1, 0);
        int ans = 0;
        for (int x : nums) {
            // use x as x+1 first (relies on old dp[x]), then use x as x
            dp[x + 1] = max(dp[x + 1], dp[x] + 1);
            dp[x] = max(dp[x], (x > 0 ? dp[x - 1] : 0) + 1);
            ans = max({ans, dp[x], dp[x + 1]});
        }
        return ans;
    }
};
