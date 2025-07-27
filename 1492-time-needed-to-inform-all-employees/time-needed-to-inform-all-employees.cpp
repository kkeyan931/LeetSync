class Solution {
public:
    int bfs(vector<vector<int>> adj, int node, vector<int>& informTime) {

        queue<pair<int, int>> q;

        q.push({node, 0});

        int maxTime = 0;
        while (!q.empty()) {

            auto [u, time] = q.front();
            q.pop();

            maxTime = max(maxTime, time);

            for (int v : adj[u]) {
                q.push({v, time + informTime[u]});
            }
        }
        return maxTime;
    }
    int doBfs(int n, int headID, vector<int>& manager,
              vector<int>& informTime) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; ++i) {
            if (i != headID)
                adj[manager[i]].push_back(i);
        }

        return bfs(adj, headID, informTime);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        return doBfs(n, headID, manager, informTime);
    }
};