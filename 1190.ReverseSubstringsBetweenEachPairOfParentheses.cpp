class Solution {
public:
    string reverseParentheses(string s) {
        int no = s.size();
        vector<int> pair(no, -1), st;
        for (int i = 0; i < no; ++i) {
            if (s[i] == '(') st.push_back(i);
            else if (s[i] == ')') {
                int j = st.back(); st.pop_back();
                pair[i] = j; pair[j] = i;
            }
        }
        string res;
        for (int i = 0, d = 1; i < no; i += d) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                d = -d;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};

