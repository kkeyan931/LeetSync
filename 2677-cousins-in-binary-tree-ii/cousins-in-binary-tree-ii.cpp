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
    TreeNode* replaceValueInTree(TreeNode* root) {
        /*
            1. get the level sum for each level
            2. negate the direct siblings value
        */

        vector<int> levelSum;
        queue<TreeNode*> queue;

        queue.push(root);
        while (!queue.empty()) {
            int size = queue.size();

            int sum = 0;
            while (size--) {
                auto front = queue.front();
                queue.pop();

                sum += front->val;

                if (front->left) {
                    queue.push(front->left);
                }
                if (front->right) {
                    queue.push(front->right);
                }
            }
            levelSum.push_back(sum);
        }

        queue.push(root);
        root->val = 0;

        int index = 1;
        while (!queue.empty()) {

            int size = queue.size();

            while (size--) {

                auto front = queue.front();
                queue.pop();

                int siblingsSum = (front->left ? front->left->val : 0) +
                                  (front->right ? front->right->val : 0);

                if (front->left) {
                    front->left->val = levelSum[index] - siblingsSum;
                    queue.push(front->left);
                }
                if (front->right) {
                    front->right->val = levelSum[index] - siblingsSum;
                    queue.push(front->right);
                }
            }
            index++;
        }
        return root;
    }
};