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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map <int, map<int, multiset<int>>> map;

        queue<tuple<TreeNode*, int, int>> q;

        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, col, row] = q.front();
            q.pop();

            map[col][row].insert(node->val);

            if (node->left) {
                q.push({node->left, col - 1, row + 1});
            }
            if (node->right) {
                q.push({node->right, col + 1, row + 1});
            }
        }

        vector<vector<int>> result;
        for (auto& [col, rowMap] : map) {
            vector<int> temp;
            for (auto& [row, mset] : rowMap) {
                for (auto it = mset.begin(); it != mset.end(); ++it) {
                    temp.push_back(*it);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};