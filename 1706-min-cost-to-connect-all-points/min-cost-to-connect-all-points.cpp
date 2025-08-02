class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    bool unionBySize(int u, int v) {
        int ul_u = findParent(u);
        int ul_v = findParent(v);

        if (ul_u == ul_v) {
            return false;
        }
        if (size[ul_u] > size[ul_v]) {
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        } else {
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }
        return true;
    }
};
class Solution {
public:
    int kruskal(vector<vector<int>>& points) {
        int n = points.size();

        vector<tuple<int, int, int>> adj;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                adj.push_back({abs(points[i][0] - points[j][0]) +
                                   abs(points[i][1] - points[j][1]),
                               i, j});
            }
        }
        sort(adj.begin(), adj.end());

        DSU dsu = DSU(n);

        int sum = 0;
        for (auto [weight, u, v] : adj) {
            if (dsu.findParent(u) != dsu.findParent(v)) {
                sum += weight;
                dsu.unionBySize(u, v);
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        return kruskal(points);
    }
};