class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dfs(vector<vector<int>>& grid, int row, int col) {

        int count = 0;
        for (auto [dr, dc] : directions) {
            int nr = dr + row;
            int nc = dc + col;

            if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size()) {
                continue;
            }

            if (grid[nr][nc] == 0) {
                continue;
            }

            grid[nr][nc] = 0;

            count += 1 + dfs(grid, nr, nc);
        }
        return count;
    }
    int doDFS(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxi = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    maxi = max(maxi, dfs(grid, i, j) + 1);
                }
            }
        }
        return maxi;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        return doDFS(grid);
    }
};