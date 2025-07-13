struct TrieNode {
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    bool isEnd;
    TrieNode() { isEnd = false; }
};
class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* ptr = root;

        for (auto ch : word) {
            if (ptr->children[ch - 'a'] == nullptr) {
                ptr->children[ch - 'a'] = new TrieNode();
            }
            ptr = ptr->children[ch - 'a'];
        }
        ptr->isEnd = true;
    }

    bool search(string word) {
        TrieNode* ptr = root;

        for (auto ch : word) {
            if (ptr->children[ch - 'a'] == nullptr) {
                return false;
            }
            ptr = ptr->children[ch - 'a'];
        }
        if (ptr->isEnd) {
            return true;
        }
        return false;
    }

    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        for (auto ch : prefix) {
            if (ptr->children[ch - 'a'] == nullptr) {
                return false;
            }
            ptr = ptr->children[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */