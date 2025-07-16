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

    int maxi = INT_MIN;
    int rec(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        int l = rec(root->left);
        int r = rec(root->right);
        
        maxi = max(root->val, maxi);
        maxi = max(root->val + l, maxi);
        maxi = max(root->val + r, maxi);
        maxi = max(root->val + l + r, maxi);

        return max(root->val, max(root->val + l, root->val + r));
    }
    int maxPathSum(TreeNode* root) {
        rec(root);
        return maxi;
    }
};