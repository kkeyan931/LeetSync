class Solution {
public:
    bool canPlace(int row, int col, int n, vector<string>& board) {

        // column
        for (int i = 0; i < n; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        int i = row, j = col;
        // upper left diagnol
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }
        i = row, j = col;
        // upper right diagnol
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    int bt(int row, int n, vector<string>& board) {
        if (row == n) {
            return 1;
        }
        
        int count = 0;
        for (int col = 0; col < n; ++col) {
            if (canPlace(row, col, n, board)) {
                board[row][col] = 'Q';
                count += bt(row + 1, n, board);
                board[row][col] = '.';
            }
        }
        return count;
    }
    int totalNQueens(int n) {
        vector<string> board(n);

        for (int i = 0; i < n; ++i) {
            string row = "";
            for (int j = 0; j < n; ++j) {
                row += ".";
            }
            board[i] = row;
        }
        return bt(0, n, board);
    }
};