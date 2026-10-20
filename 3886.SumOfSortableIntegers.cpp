#include <bits/stdc++.h>
using namespace std;

// 3886. Sum of Sortable Integers (LeetCode Daily Challenge 2026-10-20)
// For each divisor k of n, every block of length k must be a cyclic rotation of
// a sorted sequence (at most one cyclic descent), and consecutive blocks must not
// overlap in value range (max of block <= min of next block).
// Time: O(d(n) * n), Space: O(1)

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;
            bool ok = true;
            int prevMax = INT_MIN;
            for (int s = 0; s < n && ok; s += k) {
                int descents = 0, mn = INT_MAX, mx = INT_MIN;
                for (int i = 0; i < k; ++i) {
                    int a = nums[s + i], b = nums[s + (i + 1) % k];
                    if (a > b) ++descents;
                    mn = min(mn, a);
                    mx = max(mx, a);
                }
                if (descents > 1 || mn < prevMax) ok = false;
                prevMax = mx;
            }
            if (ok) total += k;
        }
        return (int)total;
    }
};
