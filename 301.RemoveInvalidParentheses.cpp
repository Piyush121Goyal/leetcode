class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // Count the minimum number of '(' and ')' that must be removed.
        int lRem = 0, rRem = 0;
        for (char c : s) {
            if (c == '(') lRem++;
            else if (c == ')') {
                if (lRem > 0) lRem--;
                else rRem++;
            }
        }
        vector<string> res;
        string cur;
        dfs(s, 0, lRem, rRem, 0, true, cur, res);
        return res;
    }

private:
    // keptPrev: whether s[i-1] was kept. Within a run of identical parentheses,
    // removals must form a prefix of the run, which avoids duplicate results.
    void dfs(const string& s, int i, int lRem, int rRem, int open, bool keptPrev,
             string& cur, vector<string>& res) {
        if (i == (int)s.size()) {
            if (lRem == 0 && rRem == 0 && open == 0) res.push_back(cur);
            return;
        }
        char c = s[i];
        if (c == '(' || c == ')') {
            bool canRemove = (c == '(') ? lRem > 0 : rRem > 0;
            bool dupe = (i > 0 && s[i - 1] == c && keptPrev);
            if (canRemove && !dupe) {
                dfs(s, i + 1, lRem - (c == '('), rRem - (c == ')'), open, false, cur, res);
            }
            int nOpen = open + (c == '(' ? 1 : -1);
            if (nOpen >= 0) {
                cur.push_back(c);
                dfs(s, i + 1, lRem, rRem, nOpen, true, cur, res);
                cur.pop_back();
            }
        } else {
            cur.push_back(c);
            dfs(s, i + 1, lRem, rRem, open, true, cur, res);
            cur.pop_back();
        }
    }
};
