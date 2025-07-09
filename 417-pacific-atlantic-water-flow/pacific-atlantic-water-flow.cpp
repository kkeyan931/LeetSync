class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& heights, int row, int col,
             vector<vector<bool>>& visited) {
        visited[row][col] = true;

        int m = heights.size();
        int n = heights[0].size();
        for (auto [dr, dc] : directions) {
            int nr = dr + row;
            int nc = dc + col;

            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if (visited[nr][nc])
                continue;
            
            if(heights[row][col] > heights[nr][nc]) continue;

            dfs(heights, nr, nc, visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pVis(m, vector<bool>(n, false));
        vector<vector<bool>> aVis(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            dfs(heights, i, 0, pVis);
            dfs(heights, i, n - 1, aVis);
        }

        for (int i = 0; i < n; ++i) {
            dfs(heights, 0, i, pVis);
            dfs(heights, m - 1, i, aVis);
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pVis[i][j] && aVis[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};