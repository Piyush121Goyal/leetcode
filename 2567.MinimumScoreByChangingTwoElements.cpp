class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        // Changing two elements to match existing values makes the low score 0,
        // so we only need to minimize the high score (max - min).
        // After sorting, the best choice is to change two of the extreme values:
        // both smallest, both largest, or one smallest and one largest.
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min({nums[n - 1] - nums[2],
                    nums[n - 3] - nums[0],
                    nums[n - 2] - nums[1]});
    }
};
