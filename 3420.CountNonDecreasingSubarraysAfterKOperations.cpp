class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;  // prefix-max indices of window [l, r], increasing index
        long long cost = 0, ans = 0;
        int r = n - 1;
        for (int l = n - 1; l >= 0; --l) {
            while (!dq.empty() && nums[dq.front()] <= nums[l]) {
                int f = dq.front();
                dq.pop_front();
                int nxt = dq.empty() ? r + 1 : dq.front();
                cost += (long long)(nums[l] - nums[f]) * (nxt - f);
            }
            dq.push_front(l);
            while (cost > k) {
                cost -= nums[dq.back()] - nums[r];
                if (dq.back() == r) dq.pop_back();
                --r;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};
