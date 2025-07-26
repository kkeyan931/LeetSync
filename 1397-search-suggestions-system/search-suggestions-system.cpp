struct TrieNode {
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    string word = "";
};
class Solution {
public:
    TrieNode* root = new TrieNode();
    void dfs(TrieNode* root, vector<string>& result, int k) {
        if (root->word != "") {
            result.push_back(root->word);
        }
        if (result.size() == k) {
            return;
        }
        for (TrieNode* child : root->children) {
            if (child) {
                dfs(child, result, k);
                if (result.size() == k) {
                    return;
                }
            }
        }
    }
    void insert(string &word) {
        TrieNode* ptr = root;

        for(auto ch : word) {
            if(ptr->children[ch - 'a'] == nullptr) {
                ptr->children[ch - 'a'] = new TrieNode();
            }
            ptr = ptr->children[ch - 'a'];
        }
        ptr->word = word;
    }
    TrieNode* getNode(string &word) {
        TrieNode* ptr = root;
        for(auto ch : word) {
            if(ptr->children[ch - 'a']) {
                ptr = ptr->children[ch - 'a'];
            } else {
                return nullptr;
            }
        }
        return ptr;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {


        for(auto &str : products) {
            insert(str);
        }

        vector<vector<string>> result(searchWord.size());                             
        for(int i = 1; i <= searchWord.size(); ++i) {
            string str = searchWord.substr(0, i);
            TrieNode* node = getNode(str);
            if(node == nullptr) {
                return result;
            }
            vector<string> words;

            dfs(node, words, 3);
            if(words.size() == 0) {
                return result;
            }
            result[i-1] = words;
        }

        return result;
    }
};