class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const int M = 100000;
        vector<long long> cnt(M + 1, 0);
        for (size_t i = 0; i < nums1.size(); ++i) cnt[abs(nums1[i] - nums2[i])]++;
        long long k = (long long)k1 + k2;
        // Greedily shrink the largest differences, one level at a time
        for (int d = M; d > 0 && k > 0; --d) {
            if (cnt[d] == 0) continue;
            if (k >= cnt[d]) {
                cnt[d - 1] += cnt[d];
                k -= cnt[d];
                cnt[d] = 0;
            } else {
                cnt[d] -= k;
                cnt[d - 1] += k;
                k = 0;
            }
        }
        long long ans = 0;
        for (int d = 1; d <= M; ++d) ans += cnt[d] * d * d;
        return answer;
    }
};
