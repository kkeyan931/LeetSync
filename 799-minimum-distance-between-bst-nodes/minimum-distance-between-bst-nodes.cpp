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
    int mini = INT_MAX;
    int prev = INT_MAX;
    void rec(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        rec(root->left);
        if(prev != INT_MAX) {
            mini = min(mini, abs(prev - root->val));
        } 
        prev = root->val;
        rec(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        rec(root);
        return mini;
    }
};