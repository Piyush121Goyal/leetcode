class Solution {
public:
    bool isValid(string s) {
        // Stack-based matching: O(n) time, O(n) space.
        string st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push_back(c);
            } else {
                if (st.empty()) return false;
                char t = st.back();
                if ((c == ')' && t != '(') ||
                    (c == ']' && t != '[') ||
                    (c == '}' && t != '{')) return false;
                st.pop_back();
            }
        }
        return st.empty();
    }
};
