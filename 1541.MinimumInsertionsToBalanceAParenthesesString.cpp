class Solution {
public:
    int minInsertions(string s) {
        int res = 0, need = 0; // need = number of ')' still required
        for (char c : s) {
            if (c == '(') {
                need += 2;
                if (need % 2 == 1) { // odd: insert a ')' to close the previous pair
                    res++;
                    need--;
                }
            } else {
                need--;
                if (need == -1) { // unmatched ')': insert a '('
                    res++;
                    need = 1;
                }
            }
        }
        return res + need;
    }
};
