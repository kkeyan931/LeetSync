class Solution {
public:
    bool canPlace(int row, int col, int n, vector<string> &board) {
        
        // column
        for(int i = 0; i < n; ++i) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        int i = row, j = col;
        // upper left diagnol
        while(i >= 0 && j >=0) {
            if(board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }
        i = row, j = col;
        // upper right diagnol
        while(i >= 0 && j < n) {
            if(board[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    void bt(int row, int n, vector<vector<string>> &result, vector<string> &board) {
        if(row == n) {
            result.push_back(board);
            return;
        }

        for(int col = 0; col < n; ++col) {
            if(canPlace(row, col, n, board)) {
                board[row][col] = 'Q';
                bt(row + 1, n, result, board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n);

        for(int i = 0; i < n; ++i) {
            string row = "";
            for(int j = 0; j < n; ++j) {
                row += ".";
            }
            board[i] = row;
        }
        bt(0, n, result, board);
        return result;
    }
};