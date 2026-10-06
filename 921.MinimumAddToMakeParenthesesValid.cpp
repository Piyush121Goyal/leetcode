class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;   // unmatched '(' so far
        int adds = 0;   // ')' with no matching '(' -> need an inserted '('
        for (char c : s) {
            if (c == '(') {
                open++;
            } else if (open > 0) {
                open--;
            } else {
                adds++;
            }
        }
        return adds + open;  // remaining '(' each need a ')'
    }
};
