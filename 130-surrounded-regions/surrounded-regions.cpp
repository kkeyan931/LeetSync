class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& board, int row, int col) {

        int n = board.size();
        int m = board[0].size();

        if (board[row][col] != 'O')
            return;

        board[row][col] = 'E';
        for (auto [dr, dc] : directions) {
            int nr = row + dr;
            int nc = col + dc;

            if (nr >= n || nc >= m || nr < 0 || nc < 0) {
                continue;
            }
            dfs(board, nr, nc);
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0)
            return;
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    dfs(board, i, j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'E')
                    board[i][j] = 'O';
            }
        }
    }
};