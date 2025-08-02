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
    int index = 0;
    TreeNode* construct(vector<int>& preorder, int minLimit, int maxLimit) {
        if (index == preorder.size()) {
            return nullptr;
        }

        int val = preorder[index];

        if (val < minLimit || val > maxLimit) {
            return nullptr;
        }
        index++;

        TreeNode* root = new TreeNode(val);
        root->left = construct(preorder, minLimit, root->val);
        root->right = construct(preorder, root->val, maxLimit);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, INT_MIN, INT_MAX);
    }
};