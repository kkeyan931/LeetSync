class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [uWeight, u] = pq.top();
            pq.pop();

            if (uWeight > dist[u])
                continue; // Skip outdated entries

            for (auto [v, vWeight] : adj[u]) {
                if (dist[v] > dist[u] + vWeight) {
                    dist[v] = dist[u] + vWeight;
                    pq.push({dist[v], v});
                }
            }
        }

        int maxTime = *max_element(dist.begin() + 1, dist.end());
        return maxTime == INT_MAX ? -1 : maxTime;
    }
};
