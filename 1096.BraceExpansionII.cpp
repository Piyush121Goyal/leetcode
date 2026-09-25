class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> res = parseUnion(expression, i);
        return vector<string>(res.begin(), res.end());
    }

private:
    // union := concat (',' concat)*
    set<string> parseUnion(const string& s, int& i) {
        set<string> res = parseConcat(s, i);
        while (i < (int)s.size() && s[i] == ',') {
            ++i;
            set<string> t = parseConcat(s, i);
            res.insert(t.begin(), t.end());
        }
        return res;
    }

    // concat := term+, where term is a letter or '{' union '}'
    set<string> parseConcat(const string& s, int& i) {
        set<string> res = {""};
        while (i < (int)s.size() && s[i] != ',' && s[i] != '}') {
            set<string> term;
            if (s[i] == '{') {
                ++i;                       // skip '{'
                term = parseUnion(s, i);
                ++i;                       // skip '}'
            } else {
                term = {string(1, s[i])};
                ++i;
            }
            set<string> next;
            for (const auto& a : res)
                for (const auto& b : term)
                    next.insert(a + b);
            res = move(next);
        }
        return res;
    }
};
