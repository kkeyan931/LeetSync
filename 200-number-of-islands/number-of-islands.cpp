class Solution {
public:
    vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>> &grid, int row, int col) {
        grid[row][col] = '0';

        for(auto [dr, dc] : directions) {
            int nr = row + dr;
            int nc = col + dc;

            if(nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size()) continue;

            if(grid[nr][nc] == '0') continue;

            dfs(grid, nr, nc);
        }
    }
    int doDFS(vector<vector<char>> &grid) {
        int count = 0;

        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
    int numIslands(vector<vector<char>>& grid) {
        return doDFS(grid);
    }
};