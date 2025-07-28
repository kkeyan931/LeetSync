class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        priority_queue<pair<double, int>> pq;
        unordered_map<int, vector<pair<int, double>>> adj;

        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            double pathProb = succProb[i];
            adj[u].push_back({v, pathProb});
            adj[v].push_back({u, pathProb});
        }
        vector<double> maxProb(n, 0.0);
        pq.push({1, start_node});

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            if (node == end_node) {
                return prob;
            }
            for (auto [nextNode, weight] : adj[node]) {

                if (maxProb[nextNode] < prob * weight) {
                    maxProb[nextNode] = prob * weight;
                    pq.push({prob * weight, nextNode});
                }
            }
        }
        return 0;
    }
};