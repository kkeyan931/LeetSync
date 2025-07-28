class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int doBFS(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;

        queue<tuple<int, int, int>> q;
        q.push({0, 0, k});

        // visited[row][col][remaining k]
        vector<vector<vector<bool>>> visited(
            n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
        visited[0][0][k] = true;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [row, col, remK] = q.front();
                q.pop();

                if (row == n - 1 && col == m - 1)
                    return time;

                for (auto [dr, dc] : directions) {
                    int nr = row + dr;
                    int nc = col + dc;

                    if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                        continue;

                    int nextRemK = remK - grid[nr][nc];

                    if (nextRemK < 0)
                        continue;

                    if (visited[nr][nc][nextRemK])
                        continue;

                    visited[nr][nc][nextRemK] = true;
                    q.push({nr, nc, nextRemK});
                }
            }
            time++;
        }
        return -1;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        return doBFS(grid, k);
    }
};
