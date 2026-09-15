class Solution {
public:
int maxPalindromes(string s, int k) {
  int n = s.size();
vector<vector<bool>> isPal(n, vector<bool>(n, false));
for (int i = n - 1; i >= 0; i--) {
for (int j = i; j < n; j++) {
if (i == j) isPal[i][j] = true;
else if (j == i + 1) isPal[i][j] = (s[i] == s[j]);
else isPal[i][j] = (s[i] == s[j] && isPal[i + 1][j - 1]);
}
}
vector<int> dp(n + 1, 0);
for (int i = 0; i < n; i++) {
dp[i + 1] = max(dp[i + 1], dp[i]);
for (int j = i + k - 1; j < n; j++) {
if (isPal[i][j]) {
dp[j + 1] = max(dp[j + 1], dp[i] + 1);
break;
}
}
}
return dp[n];
}
};
