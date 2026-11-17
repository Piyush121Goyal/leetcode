class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> divs(n + 1);
        for (int d = 1; d <= n; ++d)
            for (int L = 2 * d; L <= n; L += d)
                divs[L].push_back(d);

        const int INF = 1e9;
        // cost[i][j]: min changes to make s[i..j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int L = j - i + 1, best = INF;
                for (int d : divs[L]) {
                    int c = 0, m = L / d;
                    for (int r = 0; r < d && c < best; ++r)
                        for (int a = 0, b = m - 1; a < b; ++a, --b)
                            if (s[i + r + a * d] != s[i + r + b * d]) ++c;
                    best = min(best, c);
                }
                cost[i][j] = best;
            }
        }

        // dp[p][i]: min changes to split prefix s[0..i-1] into p parts
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        for (int p = 1; p <= k; ++p)
            for (int i = 2 * p; i <= n; ++i)
                for (int j = 2 * (p - 1); j <= i - 2; ++j)
                    if (dp[p - 1][j] < INF)
                        dp[p][i] = min(dp[p][i], dp[p - 1][j] + cost[j][i - 1]);
        return dp[k][n];
    }
};
