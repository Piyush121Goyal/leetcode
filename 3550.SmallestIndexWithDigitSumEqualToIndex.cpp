class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            int xy = nums[i], s = 0;
            while (xy > 0) {
                s += xy % 10;
                xy /= 10;
            }
            if (s == i) return i;
        }
        return -1;
    }
};
