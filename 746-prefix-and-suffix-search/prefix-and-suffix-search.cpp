class TrieNode {
public:
    int index;
    vector<TrieNode*> children;
    TrieNode() {
        index = -1;
        children = vector<TrieNode*>(27, nullptr);
    }
    void insert(string word, int index) {
        TrieNode* ptr = this;
        bool seen = false;
        for (auto& ch : word) {
            int childIndex = ch == '#' ? 26 : ch - 'a';
            if (ptr->children[childIndex] == nullptr) {
                ptr->children[childIndex] = new TrieNode();
            }
            if (ch == '#') {
                seen = true;
            }
            if (seen) {
                ptr->children[childIndex]->index =
                    max(ptr->children[childIndex]->index, index);
            }
            ptr = ptr->children[childIndex];
        }
    }
    int search(string word) {
        TrieNode* ptr = this;

        for (auto& ch : word) {
            int index = ch == '#' ? 26 : ch - 'a';
            if (ptr->children[index] == nullptr) {
                return -1;
            }
            ptr = ptr->children[index];
        }
        return ptr->index;
    }
};
class WordFilter {
public:
    TrieNode* root = new TrieNode();
    WordFilter(vector<string>& words) {
        int index = 0;
        for (auto& word : words) {
            string suffix = "";
            for (int i = 0; i < word.size(); ++i) {
                suffix = word.substr(word.size() - i - 1, 1) + suffix;
                root->insert(suffix + "#" + word, index);
            }
            index++;
        }
    }

    int f(string pref, string suff) {
        string toSearch = suff + "#" + pref;
        return root->search(toSearch);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */