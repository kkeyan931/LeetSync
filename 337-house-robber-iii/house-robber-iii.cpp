/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> dfs(TreeNode* root) {
        if (!root)
            return {0, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int include = root->val + left.second + right.second;
        int exclude =
            max(left.first, left.second) + max(right.first, right.second);

        return {include, exclude};
    }
    int optimal(TreeNode* root) {
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }
    int rec(TreeNode* root, unordered_map<TreeNode*, int>& memo) {
        if (root == nullptr) {
            return 0;
        }
        if (memo.find(root) != memo.end()) {
            return memo[root];
        }
        int include = root->val;
        if (root->left) {
            include +=
                rec(root->left->left, memo) + rec(root->left->right, memo);
        }
        if (root->right) {
            include +=
                rec(root->right->left, memo) + rec(root->right->right, memo);
        }
        int exclude = rec(root->left, memo) + rec(root->right, memo);

        return memo[root] = max(include, exclude);
    }
    int better(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        return rec(root, memo);
    }
    int rob(TreeNode* root) {
        // return better(root);
        return optimal(root);
    }
};