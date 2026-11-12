class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int best = 1, inc = 1, dec = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > nums[i - 1]) { inc++; dec = 1; }
            else if (nums[i] < nums[i - 1]) { dec++; inc = 1; }
            else { inc = dec = 1; }
            best = max(best, max(inc, dec));
        }
        return best;
    }
};
