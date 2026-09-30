// LeetCode 3. Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without
// repeating characters.
// Approach: sliding window with last-seen index per character.
// O(n) time, O(1) space (fixed 256-size table).

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);  // last index where each char appeared
        int best = 0, left = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            unsigned char c = s[right];
            if (last[c] >= left) {
                left = last[c] + 1;  // jump past the previous occurrence
            }
            last[c] = right;
            best = max(best, right - left + 1);
        }
        return best;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;  // 3
    cout << sol.lengthOfLongestSubstring("bbbbb") << endl;     // 1
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;    // 3
    return 0;
}
