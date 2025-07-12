class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if (n == 1) {
            return {0};
        }
        vector<int> result;
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(n, 0);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
            inDegree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 1) {
                inDegree[i]--;
                q.push(i);
            }
        }

        int processed = 0;
        while (n - processed > 2) {
            int size = q.size();
            processed += size;
            while (size--) {
                int node = q.front();
                q.pop();

                for (auto nextNode : adj[node]) {
                    inDegree[nextNode]--;
                    if (inDegree[nextNode] == 1) {
                        q.push(nextNode);
                    }
                }
            }
        }
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};