class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // Impossible if even all 9s can't reach the sum.
        if ((long long)sum > 9LL * num) return "";
        // Greedy: squares are convex, so concentrate the sum into as many 9s as
        // possible, placed leftmost (also yields the largest integer).
        string res;
        res.reserve(num);
        for (int i = 0; i < num; ++i) {
            int d = min(9, sum);
            res.push_back('0' + d);
            sum -= d;
        }
        return res;
    }
};
