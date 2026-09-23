class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long target = accumulate(nums.begin(), nums.end(), 0LL) - x;
        int n = nums.size();
        if (target < 0) return -1;
        if (target == 0) return n;
        long long sum = 0;
        int best = -1, l = 0;
        for (int r = 0; r < n; ++r) {
            sum += nums[r];
            while (sum > target && l <= r) sum -= nums[l++];
            if (sum == target) best = max(best, r - l + 1);
        }
        return best == -1 ? -1 : n - best;
    }
};
