class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 1; i <= n; ++i) {
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
            return false; // found a cycle
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        DSU dsu = DSU(n);

        int a, b;
        for (auto edge : edges) {
            if (!dsu.unionBySize(edge[0], edge[1])) {
                a = edge[0];
                b = edge[1];
            }
        }
        return {a, b};
    }
};