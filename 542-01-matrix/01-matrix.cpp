class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        queue<pair<int,int>> q;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            for(auto [dr, dc] : directions) {
                
                int nr = dr + row;
                int nc = dc + col;

                if(nr >= n || nc >= m || nr < 0 || nc < 0) {
                    continue;
                }
                if(mat[nr][nc] == 0) {
                    continue;
                }
                
                if(dist[nr][nc] > dist[row][col] + 1) {
                    dist[nr][nc] = dist[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return dist;
    }
};