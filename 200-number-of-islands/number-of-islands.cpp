
class DSU {
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionn(int u, int v) {
        int ul_u = findParent(u);
        int ul_v = findParent(v);

        if (ul_u == ul_v) {
            return;
        }
        if (size[ul_u] > size[ul_v]) {
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        } else {
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }
    }
};

class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = '0';

        for (auto [dr, dc] : directions) {
            int nr = row + dr;
            int nc = col + dc;

            if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size())
                continue;

            if (grid[nr][nc] == '0')
                continue;

            dfs(grid, nr, nc);
        }
    }
    int doDFS(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
    void bfs(vector<vector<char>>& grid, int row, int col) {

        grid[row][col] = '0';

        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()) {
            auto [cr, cc] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int nr = cr + dr;
                int nc = cc + dc;

                if (nr < 0 || nc < 0 || nr >= grid.size() ||
                    nc >= grid[0].size())
                    continue;

                if (grid[nr][nc] == '0')
                    continue;

                grid[nr][nc] = '0';

                q.push({nr, nc});
            }
        }
    }
    int doBFS(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }
    int doDSU(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DSU dsu(m * n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0')
                    continue;

                int u = i * n + j;

                for (auto [dr, dc] : directions) {
                    int ni = i + dr;
                    int nj = j + dc;

                    if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                        continue;
                    if (grid[ni][nj] == '0')
                        continue;

                    int v = ni * n + nj;
                    dsu.unionn(u, v);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m * n; ++i) {
            int row = i / n;
            int col = i % n;
            if (i == dsu.findParent(i) && grid[row][col] == '1') {
                count++;
            }
        }
        return count;
    }
    int numIslands(vector<vector<char>>& grid) {
        // return doDFS(grid);
        // return doBFS(grid);
        return doDSU(grid);
    }
};