class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        typedef tuple<int, int, int> tp; // (effort, row, col)
        priority_queue<tp, vector<tp>, greater<tp>> pq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, 0, 0}); // (effort, row, col)

        while (!pq.empty()) {
            auto [effort, row, col] = pq.top();
            pq.pop();

            if (row == n - 1 && col == m - 1) {
                return effort;
            }

            for (auto [dr, dc] : directions) {
                int nr = row + dr;
                int nc = col + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int cost = abs(heights[row][col] - heights[nr][nc]);
                    int maxEffort = max(effort, cost);

                    if (dist[nr][nc] > maxEffort) {
                        dist[nr][nc] = maxEffort;
                        pq.push({maxEffort, nr, nc});
                    }
                }
            }
        }
        return 0; // Should never reach here
    }
};
