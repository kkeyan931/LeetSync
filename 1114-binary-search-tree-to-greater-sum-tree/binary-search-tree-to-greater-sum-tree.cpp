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
    int prev = 0;
    void dfs(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        dfs(root->right);
        
        root->val = root->val + prev;
        prev = root->val;

        dfs(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);

        return root;
    }
};