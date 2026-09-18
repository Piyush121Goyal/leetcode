class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        int first[26], last[26];
        fill(first, first + 26, -1);
        fill(last, last + 26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int,int>> intervals; // {L, R}

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] != i) continue; // only start at first occurrence

            int L = i, R = last[c];
            int j = L;
            bool valid = true;
            while (j <= R) {
                int cj = s[j] - 'a';
                if (first[cj] < L) {
                    valid = false;
                    break;
                }
                R = max(R, last[cj]);
                j++;
            }
            if (valid) {
                intervals.push_back({L, R});
            }
        }

        // sort by right endpoint
        sort(intervals.begin(), intervals.end(),
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 return a.second < b.second;
             });

        vector<string> res;
        int lastEnd = -1;
        for (auto& [L, R] : intervals) {
            if (L > lastEnd) {
                res.push_back(s.substr(L, R - L + 1));
                lastEnd = R;
            }
        }
        return res;
    }
};
