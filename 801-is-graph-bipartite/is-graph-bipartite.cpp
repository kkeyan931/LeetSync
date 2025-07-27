class Solution {
public:
    bool bfs(int node, vector<int>& color, vector<vector<int>>& graph) {
        queue<int> q;

        q.push(node);

        color[node] = 0;

        while (!q.empty()) {
            node = q.front();
            q.pop();

            for (auto nextNode : graph[node]) {
                if (color[nextNode] == -1) {
                    color[nextNode] = !color[node];
                    q.push(nextNode);
                } else if (color[nextNode] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool doBFS(int V, vector<vector<int>>& graph) {
        vector<int> color(V, -1);

        for (int i = 0; i < V; ++i) {
            if (color[i] == -1) {
                if (!bfs(i, color, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        return doBFS(graph.size(), graph);
    }
};