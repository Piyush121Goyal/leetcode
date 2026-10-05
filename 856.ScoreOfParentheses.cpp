class Solution {
public:
    int scoreOfParentheses(string s) {
        // Each innermost "()" at depth d contributes 2^d to the total.
        int score = 0, depth = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') {
                ++depth;
            } else {
                --depth;
                if (s[i - 1] == '(') score += 1 << depth;
            }
        }
        return score;
    }
};
