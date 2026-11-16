class Solution {
public:
    string digitSum(string s, int k) {
        while ((int)s.size() > k) {
            string next;
            for (int i = 0; i < (int)s.size(); i += k) {
                int sum = 0;
                for (int j = i; j < min((int)s.size(), i + k); ++j) sum += s[j] - '0';
                next += to_string(sum);
            }
            s = next;
        }
        return s;
    }
};
