struct TrieNode {
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    bool word = false;
};

class WordDictionary {
    TrieNode* trie;

public:
    WordDictionary() { trie = new TrieNode(); }

    void addWord(string word) {
        TrieNode* node = trie;

        for (char ch : word) {
            if (!node->children[ch - 'a']) {
                node->children[ch - 'a'] = new TrieNode();
            }
            node = node->children[ch - 'a'];
        }
        node->word = true;
    }

    bool searchInNode(string word, TrieNode* node) {
        for (int i = 0; i < word.length(); ++i) {
            char ch = word[i];
            if (ch != '.' && !node->children[ch - 'a']) {
                return false;
            }
            if (ch == '.') {
                for (auto x : node->children) {
                    if (x && searchInNode(word.substr(i + 1), x)) {
                        return true;
                    }
                }
                return false;
            } else {
                // If the character is found
                // go down to the next level in trie
                node = node->children[ch - 'a'];
            }
        }
        return node->word;
    }

    bool search(string word) { return searchInNode(word, trie); }
};