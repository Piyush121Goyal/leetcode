class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int res = -1; // all bits set
        bool sorted = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                res &= nums[i];
                sorted = false;
            }
        }
        return sorted ? 0 : res;
    }
};
