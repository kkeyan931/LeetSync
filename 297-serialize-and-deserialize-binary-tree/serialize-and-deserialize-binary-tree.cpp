/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if(root == nullptr) {
            return "";
        }

        queue<TreeNode*> q;

        q.push(root);

        stringstream ss;

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            if (node == nullptr) {
                ss << "#,";
            } else {
                ss << to_string(node->val) << ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data == "") {
            return nullptr;
        }

        stringstream ss(data);
        string str;
        getline(ss, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            getline(ss, str, ',');

            if (str != "#") {
                TreeNode* left = new TreeNode(stoi(str));
                node->left = left;
                q.push(left);
            }

            getline(ss, str, ',');

            if (str != "#") {
                TreeNode* right = new TreeNode(stoi(str));
                node->right = right;
                q.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));