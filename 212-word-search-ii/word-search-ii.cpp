class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool dfs(vector<vector<char>>& board, string& word, int row, int col,
             int index) {
        int n = board.size();
        int m = board[0].size();

        if (index == word.size()) {
            return true;
        }
        char ch = board[row][col];
        board[row][col] = '*';

        for (auto [dr, dc] : directions) {
            int nr = row + dr;
            int nc = col + dc;

            if (nr >= n || nc >= m || nr < 0 || nc < 0) {
                continue;
            }
            if (board[nr][nc] == '*') {
                continue;
            }
            if (board[nr][nc] != word[index]) {
                continue;
            }
            if (dfs(board, word, nr, nc, index + 1)) {
                board[row][col] = ch;
                return true;
            }
        }
        board[row][col] = ch;
        return false;
    }
    vector<string> doDFS(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        for (auto& word : words) {
            bool flag = false;
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[0].size(); ++j) {
                    if (board[i][j] == word[0] && dfs(board, word, i, j, 1)) {
                        result.push_back(word);
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
        }
        return result;
    }
    struct TrieNode {
        vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
        string word;
        int wordCount = 0;
    };
    void insertIntoTrie(TrieNode* root, string &word) {
        TrieNode* ptr = root;
        for(auto ch : word) {
            if(ptr->children[ch - 'a'] == nullptr) {
                ptr->children[ch - 'a'] = new TrieNode();
            }
            ptr = ptr->children[ch - 'a'];
        }
        ptr->wordCount++;
        ptr->word = word;
    }

    void dfsWithTrie(vector<vector<char>> &board, TrieNode* root, vector<string> &result, int row, int col) {

        if(board[row][col] == '*') {
            return;
        }
        char ch = board[row][col];
        if(root->children[ch - 'a'] == nullptr) {
            return;
        }
        board[row][col] = '*';

        root = root->children[ch - 'a'];

        if(root->wordCount > 0) {
            result.push_back(root->word);
            root->wordCount--;
        }

        for(auto [dr, dc] : directions) {
            int nr = row + dr;
            int nc = col + dc;

            if(nr >= board.size() || nc >= board[0].size() || nr < 0 || nc < 0) {
                continue;
            }
            dfsWithTrie(board, root, result, nr, nc);
        }

        board[row][col] = ch;
    }
    vector<string> doDFSWithTrie(vector<vector<char>> &board, vector<string> &words) {
        TrieNode* root = new TrieNode();

        for(auto &word : words) {
            insertIntoTrie(root, word);
        }

        int n = board.size();
        int m = board[0].size();

        vector<string> result;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                dfsWithTrie(board, root, result, i, j);
            }
        }
        return result;
    }
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        // return doDFS(board, words);

        return doDFSWithTrie(board, words);
    }
};