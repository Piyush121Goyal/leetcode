class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        auto digitSum = [](int x) {
            int s = 0;
            while (x > 0) { s += x % 10; x /= 10; }
            return s;
        };
        vector<pair<int,int>> keyed(n); // (digitSum, value)
        for (int i = 0; i < n; i++) keyed[i] = {digitSum(nums[i]), nums[i]};
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return keyed[a] < keyed[b]; });
        // idx[i] = original position of the element that belongs at position i
        vector<bool> seen(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (seen[i]) continue;
            int len = 0, j = i;
            while (!seen[j]) { seen[j] = true; j = idx[j]; len++; }
            swaps += len - 1;
        }
        return swaps;
    }
};
