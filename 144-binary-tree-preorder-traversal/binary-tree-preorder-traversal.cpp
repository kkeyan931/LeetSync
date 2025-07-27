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
    void preorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
    vector<int> preorderRec(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }

    vector<int> preorderIt(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }
        stack<TreeNode*> stack;
        stack.push(root);

        vector<int> result;

        while(!stack.empty()) {
            auto node = stack.top();
            stack.pop();
            result.push_back(node->val);
            if(node->right) {
                stack.push(node->right);
            }
            if(node->left) {
                stack.push(node->left);
            }
        }
        return result;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // return preorderRec(root);
        return preorderIt(root);
    }
};