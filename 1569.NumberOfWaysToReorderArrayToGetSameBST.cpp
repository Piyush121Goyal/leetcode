class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int no = nums.size();
        // Pascal's triangle for binomial coefficients
        vector<vector<long long>> C(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++)
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
        // ways(a): number of orderings of a that produce the same BST
        function<long long(vector<int>&)> ways = [&](vector<int>& a) -> long long {
            if (a.size() <= 2) return 1;
            vector<int> left, right;
            for (size_t i = 1; i < a.size(); i++) {
                if (a[i] < a[0]) left.push_back(a[i]);
                else right.push_back(a[i]);
            }
            long long l = ways(left), r = ways(right);
            return C[a.size() - 1][left.size()] * l % MOD * r % MOD;
        };
        return (int)((ways(nums) - 1 + MOD) % MOD);
    }
};
