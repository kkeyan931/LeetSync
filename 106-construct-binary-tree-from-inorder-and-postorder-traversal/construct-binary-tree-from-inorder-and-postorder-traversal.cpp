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
    TreeNode* build(vector<int>& postorder, unordered_map<int, int>& umap,
                    int& index, int i, int j) {
        if (index < 0) {
            return nullptr;
        }
        if (i == j) {
            return new TreeNode(postorder[index]);
        }
        int nodeVal = postorder[index];
        TreeNode* root = new TreeNode(nodeVal);
        int inorderIndex = umap[nodeVal];

        if (j >= inorderIndex + 1) {
            index--;
            root->right = build(postorder, umap, index, inorderIndex + 1, j);
        }
        if (inorderIndex - 1 >= i) {
            index--;
            root->left = build(postorder, umap, index, i, inorderIndex - 1);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> umap;
        for (int i = 0; i < inorder.size(); ++i) {
            umap[inorder[i]] = i;
        }
        int index = postorder.size() - 1;
        return build(postorder, umap, index, 0, inorder.size() - 1);
    }
};