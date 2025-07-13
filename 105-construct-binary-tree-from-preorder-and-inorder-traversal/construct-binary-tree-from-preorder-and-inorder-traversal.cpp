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
    TreeNode* build(vector<int>& preorder, unordered_map<int,int> &umap, int &index, int i, int j) {
        if(index >= preorder.size()) {
            return nullptr;
        }
        if(i == j) {
            return new TreeNode(preorder[index]);
        }
        int nodeVal = preorder[index];
        TreeNode* root = new TreeNode(nodeVal);
        int inorderIndex = umap[nodeVal];

        if(inorderIndex - 1 >= i) {
            index++;
            root->left = build(preorder, umap, index, i, inorderIndex - 1);
        }
        if(j >= inorderIndex + 1) {
            index++;
            root->right = build(preorder, umap, index, inorderIndex + 1, j);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> umap;
        for(int i = 0; i < inorder.size(); ++i) {
            umap[inorder[i]] = i;
        }
        int index = 0;
        return build(preorder, umap, index, 0, inorder.size() - 1);
    }
};