class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int doBFS(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<tuple<int, int, int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
            }
        }
        int maxTime = 0;

        while (!q.empty()) {
            auto [row, col, time] = q.front();
            q.pop();

            maxTime = max(maxTime, time);

            for (auto [dr, dc] : directions) {
                int nr = dr + row;
                int nc = dc + col;

                if (nr >= n || nc >= m || nr < 0 || nc < 0) {
                    continue;
                }
                if (grid[nr][nc] == 0 || grid[nr][nc] == 2) {
                    continue;
                }
                grid[nr][nc] = 2;
                q.push({nr, nc, time + 1});
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return maxTime;
    }
    int orangesRotting(vector<vector<int>>& grid) { return doBFS(grid); }
};