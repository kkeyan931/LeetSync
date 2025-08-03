class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int bt(vector<vector<int>>& grid, vector<vector<bool>>& visited,
           int walkCount, int walkRequired, int row, int col) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[row][col] == 2) {
            return walkCount == walkRequired;
        }
        visited[row][col] = true;

        int count = 0;
        for (auto [dr, dc] : directions) {
            int nr = dr + row;
            int nc = dc + col;

            if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                continue;
            }
            if (visited[nr][nc]) {
                continue;
            }
            if (grid[nr][nc] == -1) {
                continue;
            }
            count += bt(grid, visited, walkCount + 1, walkRequired, nr, nc);
        }
        visited[row][col] = false;

        return count;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int row = -1, col = -1;
        int walkCount = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    row = i;
                    col = j;
                }
                if (grid[i][j] == 0) {
                    walkCount++;
                }
            }
        }

        return bt(grid, visited, -1, walkCount, row, col);
    }
};