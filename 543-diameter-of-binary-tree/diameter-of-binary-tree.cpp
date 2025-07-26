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
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = 1 + height(root->left);
        int right = 1 + height(root->right);
        return max(left, right);
    }
    int solution1(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int lheight = height(root->left);
        int rheight = height(root->right);

        int ldiameter = solution1(root->left);
        int rdiameter = solution1(root->right);

        return max(lheight + rheight, max(ldiameter, rdiameter));
    }
    int diameter = 0;
    int solution2(TreeNode* root) {
        if(root == nullptr) {
            return -1;
        }
        int left = solution2(root->left);
        int right = solution2(root->right);

        diameter = max(diameter, left + right + 2);

        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solution2(root);
        return diameter;
    }
};