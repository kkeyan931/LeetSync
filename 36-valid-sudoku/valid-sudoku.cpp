class Solution {
public:
    bool checkRow(vector<vector<char>>& board, char num, int row, int col) {
        for (int i = 0; i < 9; ++i) {
            if (i == row)
                continue;
            if (board[i][col] == num) {
                return false;
            }
        }
        return true;
    }
    bool checkCol(vector<vector<char>>& board, char num, int row, int col) {
        for (int i = 0; i < 9; ++i) {
            if (i == col)
                continue;
            if (board[row][i] == num) {
                return false;
            }
        }
        return true;
    }
    bool checkSub(vector<vector<char>>& board, char num, int row, int col) {
        int sRow = (row / 3) * 3;
        int sCol = (col / 3) * 3;

        for (int i = sRow; i < sRow + 3; i++) {
            for (int j = sCol; j < sCol + 3; j++) {
                if (row == i && col == j)
                    continue;
                if (board[i][j] == num) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') continue;
                if (!checkRow(board, board[i][j], i, j) ||
                    !checkCol(board, board[i][j], i, j) ||
                    !checkSub(board, board[i][j], i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
};