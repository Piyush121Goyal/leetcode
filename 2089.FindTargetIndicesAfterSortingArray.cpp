class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // Count elements smaller than target and equal to target.
        // After sorting, target occupies indices [less, less + equal).
        int less = 0, equal = 0;
        for (int x : nums) {
            if (x < target) less++;
            else if (x == target) equal++;
        }
        vector<int> res;
        res.reserve(equal);
        for (int i = 0; i < equal; i++) res.push_back(less + i);
        return res;
    }
};
