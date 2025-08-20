class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool dfs(vector<vector<char>>& board, string& word, int row, int col,
             int index) {
        int m = board.size();
        int n = board[0].size();

        if (index == word.size()) {
            return true;
        }

        char ch = board[row][col];

        board[row][col] = '#';

        bool ans = false;
        for (auto [dr, dc] : directions) {
            int nr = row + dr;
            int nc = col + dc;

            if (nr < 0 || nc < 0 || nr >= m || nc >= n) {
                continue;
            }

            if (board[nr][nc] == '#') {
                continue;
            }

            if (board[nr][nc] != word[index]) {
                continue;
            }
            ans = ans || dfs(board, word, nr, nc, index + 1);
        }
        board[row][col] = ch;
        return ans;
    }

    bool doDFS(vector<vector<char>>& board, string& word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 1)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        /*
            BFS will not work here, because it'll consider all the adjacent as
           possible solution. which will not explore all the possibilities.

            [["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
            ABCESEEEFS -> expected true

            BFS will fail for the above case.

            Exploring all the paths with backtracking will work.
        */
        return doDFS(board, word);
    }
};