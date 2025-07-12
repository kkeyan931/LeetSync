/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void createParentMap(unordered_map<TreeNode*, TreeNode*>& parentMap,
                         TreeNode* root, TreeNode* parent) {
        if (root == nullptr) {
            return;
        }
        parentMap[root] = parent;
        createParentMap(parentMap, root->left, root);
        createParentMap(parentMap, root->right, root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        unordered_set<TreeNode*> visited;
        vector<int> result;

        createParentMap(parentMap, root, nullptr);

        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);

        while(k-- && !q.empty()) {
            
            int size = q.size();
            while(size--) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && visited.find(node->left) == visited.end()) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && visited.find(node->right) == visited.end()) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                auto parent = parentMap[node];
                if(parent && visited.find(parent) == visited.end()) {
                    visited.insert(parent);
                    q.push(parent);
                }
            }
        }
        if(k != -1) return {};

        while(!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};