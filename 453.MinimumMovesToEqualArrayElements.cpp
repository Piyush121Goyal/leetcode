class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Incrementing n-1 elements is equivalent to decrementing one element.
        // So every element must come down to the minimum.
        long long mn = *min_element(nums.begin(), nums.end());
        long long moves = 0;
        for (int x : nums) moves += (long long)x - mn;
        return (int)moves;
    }
};
