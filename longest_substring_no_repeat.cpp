
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);  
        int best = 0, left = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            unsigned char c = s[right];
            if (last[c] >= left) {
                left = last[c] + 1; 
            }
            last[c] = right;
            best = max(best, right - left + 1);
        }
        return best;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;  
    cout << sol.lengthOfLongestSubstring("bbbbb") << endl;     
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;    
    return 0;
}
