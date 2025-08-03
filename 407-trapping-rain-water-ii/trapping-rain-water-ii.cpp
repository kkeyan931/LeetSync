class Solution {
public:
    int trapRainWater(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    pq.push({v[i][j], {i, j}});
                    vis[i][j] = 1;
                }
            }
        }
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int sum = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int height = it.first;
            int x = it.second.first;
            int y = it.second.second;
            for (int i = 0; i < 4; i++) {
                int new_x = x + dir[i].first;
                int new_y = y + dir[i].second;
                if (new_x < 0 || new_y < 0 || new_x == n || new_y == m ||
                    vis[new_x][new_y] == 1) {
                    continue;
                }
                if (v[new_x][new_y] < height) {
                    sum += height - v[new_x][new_y];
                    pq.push({height, {new_x, new_y}});
                } else {
                    pq.push({v[new_x][new_y], {new_x, new_y}});
                }

                vis[new_x][new_y] = 1;
            }
        }
        return sum;
    }
};