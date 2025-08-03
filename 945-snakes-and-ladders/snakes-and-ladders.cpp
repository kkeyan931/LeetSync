class Solution {
public:
    pair<int, int> pos(int s, int n) {
        int rFromBottom = (s - 1) / n;
        int r = n - 1 - rFromBottom;
        int cFromLeft = (s - 1) % n;
        int c = (rFromBottom % 2 == 0) ? cFromLeft : (n - 1 - cFromLeft);
        return {r, c};
    }

    int cellValue(const vector<vector<int>>& board, int s) {
        auto [r, c] = pos(s, (int)board.size());
        return board[r][c];
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = (int)board.size();
        vector<int> dist(n * n + 1, -1);
        queue<int> q;

        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == n * n)
                return dist[u];

            for (int d = 1; d <= 6 && u + d <= n * n; ++d) {
                int v = u + d;
                int val = cellValue(board, v);
                if (val != -1)
                    v = val; // ladder or snake

                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return -1; // unreachable
    }
};
