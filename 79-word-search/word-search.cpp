class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int row, int col,
             int index) {

        int rowSize = board.size();
        int colSize = board[0].size();

        if (index == word.size()) {
            return true;
        }

        if (row < 0 || col < 0 || row >= rowSize || col >= colSize) {
            return false;
        }

        if (board[row][col] == '#') {
            return false;
        }

        if (board[row][col] != word[index]) {
            return false;
        }

        char ch = board[row][col];
        board[row][col] = '#';

        bool found = false;

        found = found || dfs(board, word, row + 1, col, index + 1);
        found = found || dfs(board, word, row - 1, col, index + 1);
        found = found || dfs(board, word, row, col + 1, index + 1);
        found = found || dfs(board, word, row, col - 1, index + 1);

        board[row][col] = ch;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {

        for (int rowIndex = 0; rowIndex < board.size(); ++rowIndex) {
            for (int colIndex = 0; colIndex < board[0].size(); ++colIndex) {
                if (board[rowIndex][colIndex] == word[0] &&
                    dfs(board, word, rowIndex, colIndex, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};