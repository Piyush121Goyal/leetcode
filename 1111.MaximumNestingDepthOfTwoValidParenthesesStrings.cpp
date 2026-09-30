class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // Alternate nesting levels between A and B by depth parity,
        // so each subsequence gets roughly half of the max depth.
        int n = seq.size(), depth = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (seq[i] == '(') {
                ++depth;
                ans[i] = depth % 2;
            } else {
                ans[i] = depth % 2;
                --depth;
            }
        }
        return ans;
    }
};
