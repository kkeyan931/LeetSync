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
    int rec(TreeNode* root, unordered_map<TreeNode*, int> &memo) {
        if (root == nullptr) {
            return 0;
        }
        if(memo.find(root) != memo.end()) {
            return memo[root];
        }
        int include = root->val +
                      rec(root->left ? root->left->left : root->left, memo) +
                      rec(root->left ? root->left->right : root->left, memo) +
                      rec(root->right ? root->right->left : root->right, memo) +
                      rec(root->right ? root->right->right : root->right, memo);

        int exclude = rec(root->left, memo) + rec(root->right, memo);

        return memo[root] = max(include, exclude);
    }
    int rob(TreeNode* root) { 
        unordered_map<TreeNode*, int> memo;
        return rec(root, memo); 
    }
};