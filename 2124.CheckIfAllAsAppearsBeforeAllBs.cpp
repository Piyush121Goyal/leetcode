class Solution {
public:
    bool checkString(string s) {
        // Every 'a' precedes every 'b' iff "ba" never appears.
        return s.find("ba") == string::npos;
    }
};
