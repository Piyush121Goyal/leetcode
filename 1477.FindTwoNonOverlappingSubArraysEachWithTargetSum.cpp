#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prefix(n, INT_MAX);
        int left = 0, sum = 0;
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            int best = INT_MAX;
            if (sum == target) best = right - left + 1;
            prefix[right] = (right > 0) ? min(best, prefix[right - 1]) : best;
        }

        vector<int> suffix(n, INT_MAX);
        int right2 = n - 1, sum2 = 0;
        for (int leftIdx = n - 1; leftIdx >= 0; leftIdx--) {
            sum2 += arr[leftIdx];
            while (sum2 > target) {
                sum2 -= arr[right2];
                right2--;
            }
            int best = INT_MAX;
            if (sum2 == target) best = right2 - leftIdx + 1;
            suffix[leftIdx] = (leftIdx < n - 1) ? min(best, suffix[leftIdx + 1]) : best;
        }

        int ans = INT_MAX;
        for (int i = 0; i + 1 < n; i++) {
            if (prefix[i] != INT_MAX && suffix[i + 1] != INT_MAX) {
                ans = min(ans, prefix[i] + suffix[i + 1]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
