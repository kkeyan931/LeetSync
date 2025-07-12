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
    void rec(TreeNode* root, vector<vector<int>> &result, vector<int> &temp, int target) {
        if(root == nullptr) {
            return;
        }
        if(root->left == nullptr && root->right == nullptr) {
            temp.push_back(root->val);
            if(target - root->val == 0) {
                result.push_back(temp);
            }
            temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        rec(root->left, result, temp, target - root->val);
        rec(root->right, result, temp, target - root->val);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;
        rec(root, result, temp, targetSum);
        return result;
    }
};