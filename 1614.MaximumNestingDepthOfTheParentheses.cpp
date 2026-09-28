class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, best = 0;
        for (char c : s) {
            if (c == '(') best = max(best, ++depth);
            else if (c == ')') --depth;
        }
        return best;
    }
};
