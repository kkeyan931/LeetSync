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
    void helper(TreeNode* root, vector<string> &result, string path) {
        if(root == nullptr) {
            return;
        }
        if(root->left == nullptr && root->right == nullptr) {
            path += to_string(root->val);
            result.push_back(path);
            return;
        }
        helper(root->left, result, path + to_string(root->val) + "->");
        helper(root->right, result, path + to_string(root->val) + "->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        helper(root, result, "");
        return result;
    }
};