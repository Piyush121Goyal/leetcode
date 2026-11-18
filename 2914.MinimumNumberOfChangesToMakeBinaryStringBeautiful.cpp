class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        for (size_t i = 0; i + 1 < s.size(); i += 2) {
            if (s[i] != s[i + 1]) ++changes;
        }
        return changes;
    }
};
