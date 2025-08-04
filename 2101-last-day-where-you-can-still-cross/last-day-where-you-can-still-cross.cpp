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
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int totalCells = row * col;
        int n = totalCells + 2;

        DSU dsu = DSU(n);

        unordered_set<int> visited;

        for (int i = 1; i <= col; i++) {
            /* connect 0 to the first row*/
            dsu.unionBySize(i, 0);
        }

        for (int i = row * col; i > (row * col) - col; i--) {
            /* connect n - 1 to last row */
            dsu.unionBySize(i, n - 1);
        }

        for (int i = row * col - 1; i >= 0; i--) {
            int r = cells[i][0];
            int c = cells[i][1];

            int node = col * (r - 1) + c;

            visited.insert(node);

            for (auto [dr, dc] : directions) {

                int nr = dr + r;
                int nc = dc + c;
                int nextNode = col * (nr - 1) + nc;

                if (nr > row || nc > col || nr < 1 || nc < 1) {
                    continue;
                }
                if (visited.find(nextNode) == visited.end()) {
                    continue;
                }
                dsu.unionBySize(node, nextNode);
            }

            if (dsu.findParent(0) == dsu.findParent(n - 1)) {
                return i;
            }
        }
        return -1;
    }
};