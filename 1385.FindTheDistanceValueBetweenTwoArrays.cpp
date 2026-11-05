class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // Sort arr2, then for each x check whether any value lies in [x - d, x + d].
        sort(arr2.begin(), arr2.end());

        int count = 0;
        for (int x : arr1) {
            auto it = lower_bound(arr2.begin(), arr2.end(), x - d);
            if (it == arr2.end() || *it > x + d) {
                count++;
            }
        }
        return count;
    }
};
