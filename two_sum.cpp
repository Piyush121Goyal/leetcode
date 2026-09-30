// LeetCode 1. Two Sum
// Given an array of integers nums and an integer target, return the indices
// of the two numbers such that they add up to target.
// Approach: one pass with a hash map (value -> index). O(n) time, O(n) space.

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;  // value -> index
        for (int i = 0; i < (int)nums.size(); i++) {
            int need = target - nums[i];
            auto it = seen.find(need);
            if (it != seen.end()) {
                return {it->second, i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = sol.twoSum(nums, target);
    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;  // [0, 1]
    return 0;
}
