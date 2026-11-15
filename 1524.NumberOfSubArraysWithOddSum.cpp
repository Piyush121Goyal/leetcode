class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long odd = 0, even = 1, ans = 0;
        int sum = 0;
        for (int x : arr) {
            sum = (sum + x) & 1;
            if (sum) { ans += even; odd++; }
            else { ans += odd; even++; }
        }
        return ans % MOD;
    }
};
