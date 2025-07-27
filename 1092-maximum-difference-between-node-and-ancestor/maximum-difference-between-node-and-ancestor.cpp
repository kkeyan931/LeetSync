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
    int result = 0;
    void rec(TreeNode* root, int maxi, int mini) {
        if(root == nullptr) {
            return;
        }
        result = max(result, abs(maxi - root->val));
        result = max(result, abs(mini - root->val));

        rec(root->left, max(maxi, root->val), min(mini, root->val));
        rec(root->right, max(maxi, root->val), min(mini, root->val));
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        rec(root, root->val, root->val);
        return result;
    }
};