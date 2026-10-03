class Solution {
public:
    int longestValidParentheses(string s) {
        // Stack of indices; bottom holds the index of the last unmatched ')'
        vector<int> st;
        st.push_back(-1);
        int best = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') {
                st.push_back(i);
            } else {
                st.pop_back();
                if (st.empty()) {
                    st.push_back(i);
                } else {
                    best = max(best, i - st.back());
                }
            }
        }
        return best;
    }
};
