class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        if (s[0] == mn || s[n - 1] == mx) return 1;
        // mn somewhere in a proper prefix, or mx somewhere in a proper suffix -> 2
        for (int i = 0; i < n - 1; i++)
            if (s[i] == mn) return 2;
        for (int i = 1; i < n; i++)
            if (s[i] == mx) return 2;
        return 3;
    }
};
