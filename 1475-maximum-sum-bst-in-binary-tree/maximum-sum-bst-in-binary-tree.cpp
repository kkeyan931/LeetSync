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
    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;

        Info(bool isBST, int sum, int minVal, int maxVal)
            : isBST(isBST), sum(sum), minVal(minVal), maxVal(maxVal) {}
    };

    int maxSize = 0;

    Info dfs(TreeNode* root) {
        if (!root)
            return Info(true, 0, INT_MAX, INT_MIN);

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        if (left.isBST && right.isBST && root->val > left.maxVal &&
            root->val < right.minVal) {

            int size = left.sum + right.sum + root->val;
            maxSize = max(maxSize, size);
            return Info(true, size, min(root->val, left.minVal),
                        max(root->val, right.maxVal));
        }
        return Info(false, 0, 0, 0); // Not a BST
    }

    int maxSumBST(TreeNode* root) {
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
};
