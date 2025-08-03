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
    void buildParentMap(TreeNode* root,
                        unordered_map<TreeNode*, TreeNode*>& parentMap,
                        TreeNode* parent) {
        if (root == nullptr) {
            return;
        }
        parentMap[root] = parent;
        buildParentMap(root->left, parentMap, root);
        buildParentMap(root->right, parentMap, root);
    }
    TreeNode* getNode(TreeNode* root, int value) {
        if (root == nullptr) {
            return root;
        }
        if (root->val == value) {
            return root;
        }
        TreeNode* left = getNode(root->left, value);
        TreeNode* right = getNode(root->right, value);

        return left ? left : right;
    }
    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> parentMap;
        unordered_set<TreeNode*> visited;
        buildParentMap(root, parentMap, nullptr);

        TreeNode* startNode = getNode(root, start);

        queue<TreeNode*> q;

        q.push(startNode);

        int time = 0;
        while (!q.empty()) {
            int size = q.size();

            while (size--) {

                auto node = q.front();
                q.pop();
                visited.insert(node);

                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                }
                auto parentNode = parentMap.find(node);
                if (parentNode != parentMap.end() &&
                    parentNode->second != nullptr &&
                    visited.find(parentNode->second) == visited.end()) {
                    q.push(parentNode->second);
                }
            }
            time++;
        }
        return time - 1;
    }
};