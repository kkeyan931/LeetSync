class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dfs(vector<vector<int>>& grid, int color, int row, int col) {
        int area = 0;

        int n = grid.size();
        int m = grid[0].size();

        grid[row][col] = color;

        for (auto [dr, dc] : directions) {

            int nr = dr + row;
            int nc = dc + col;

            if (nr >= n || nc >= m || nr < 0 || nc < 0) {
                continue;
            }
            if (grid[nr][nc] != 1) {
                continue;
            }
            area += dfs(grid, color, nr, nc);
        }
        return area + 1;
    }
    int doDFS(vector<vector<int>>& grid) {

        /*
            1. find all the island size
            2. store in a map with unique identifier for each island
            3. traverse the grid for zero and count the neighbor islands
            4. return the max
        */

        int n = grid.size();
        int m = grid[0].size();

        int color = -1;
        unordered_map<int, int> countMap;
        int maxIsland = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    countMap[color] = dfs(grid, color, i, j);
                    maxIsland = max(maxIsland, countMap[color]);
                    color--;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int count = 1;
                    for (auto [dr, dc] : directions) {
                        int nr = dr + i;
                        int nc = dc + j;

                        if (nr >= n || nc >= m || nr < 0 || nc < 0) {
                            continue;
                        }
                        if (grid[nr][nc] != 0 &&
                            seen.find(grid[nr][nc]) == seen.end()) {
                            seen.insert(grid[nr][nc]);
                            count += countMap[grid[nr][nc]];
                        }
                    }
                    maxIsland = max(maxIsland, count);
                }
            }
        }
        return maxIsland;
    }
    int largestIsland(vector<vector<int>>& grid) {
        return doDFS(grid);
    }
};