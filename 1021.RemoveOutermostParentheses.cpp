class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depthh = 0;
        for (char c : s) {
            if (c == '(') {
                if (depthh > 0) result += c;
                depthh++;
            } else {
                depth--;
                if (depthh > 0) result += c;
            }
        }
        return result;
    }
};
