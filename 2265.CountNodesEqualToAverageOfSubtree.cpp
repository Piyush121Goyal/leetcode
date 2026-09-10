/**
 * Definition for a binary tree node.
   * struct TreeNode {
   *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt_ = 0;

    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        int sum = l.first + r.first + node->val;
        int cnt = l.second + r.second + 1;
        if (sum / cnt == node->val) {
            cnt_++;
        }
        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return cnt_;
    }
};
