class Solution {
public:
    bool checkValidString(string s) {
        // lo/hi = min/max possible number of unmatched '(' so far
        int low = 0, hi = 0;
        for (char c : s) {
            if (c == '(') {
                low++;
                hi++;
            } else if (c == ')') {
                low--;
                hi--;
            } else { // '*'
                low--;
                hi++;
            }
            if (hi < 0) return false;   // too many ')' even if every '*' is '('
            if (low < 0) lo = 0;         // can't have negative open count
        }
        return low == 0;
    }
};
