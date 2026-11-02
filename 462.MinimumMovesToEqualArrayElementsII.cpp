class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        // The median minimizes the sum of absolute deviations.
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        long long median = nums[n / 2];
        long long moves = 0;
        for (int x : nums) moves += llabs((long long)x - median);
        return (int)moves;
    }
};
