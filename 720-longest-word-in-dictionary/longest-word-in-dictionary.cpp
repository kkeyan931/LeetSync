struct TrieNode {
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    bool isEnd;
    TrieNode() { isEnd = false; }
};
class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string& word) {
        TrieNode* ptr = root;

        for (auto ch : word) {
            if (ptr->children[ch - 'a'] == nullptr) {
                ptr->children[ch - 'a'] = new TrieNode();
            }
            ptr = ptr->children[ch - 'a'];
        }
        ptr->isEnd = true;
    }
    bool search(string& word) {
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
    string longestWord(vector<string>& words) {
        
        string result = "";
        int maxi = 0;

        for(auto word : words) {
            insert(word);
        }

        for(auto word : words) {
            int i;
            for(i = 0; i < word.size(); ++i) {
                string subStr = word.substr(0, i + 1);
                if(!search(subStr)) {
                    break;
                }
            }
            if(i == word.size()) {
                if(maxi < word.size()) {
                    maxi = word.size();
                    result = word;
                }
                if(maxi == word.size()) {
                    if(word < result) {
                        result = word;
                    }
                }
            }
        }
        return result;
        
    }
};