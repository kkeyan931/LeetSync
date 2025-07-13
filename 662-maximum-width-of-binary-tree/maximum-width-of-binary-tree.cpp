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
    int bfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<pair<TreeNode*, unsigned long long int>> q;

        q.push({root, 0});

        int maxi = 1;
        while (!q.empty()) {
            int size = q.size();
            unsigned long long int start, end;
            for (int i = 0; i < size; ++i) {
                auto [node, c] = q.front();
                q.pop();

                if (i == 0) {
                    start = c;
                }
                if (i == size - 1) {
                    end = c;
                }

                if (node->left) {
                    q.push({node->left, (2ll * c)});
                }
                if (node->right) {
                    q.push({node->right, (2ll * c) + 1});
                }
            }
            maxi = max((unsigned long long int)maxi, (end - start) + 1);
        }
        return maxi;
    }
    int widthOfBinaryTree(TreeNode* root) {
        return bfs(root);
    }
};