class DSU {
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int findParent(int node) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ul_u = findParent(u);
        int ul_v = findParent(v);

        if(ul_u == ul_v) {
            return;
        }

        if(size[ul_u] > size[ul_v]) {
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        } else {
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        
        DSU dsu = DSU(26);
        for(auto eq : equations) {
            if(eq[1] == '=') {
                dsu.unionBySize(eq[0] - 'a', eq[3] - 'a');
            }
        }
        for(auto eq : equations) {
            if(eq[1] == '!' && dsu.findParent(eq[0] - 'a') == dsu.findParent(eq[3] - 'a')) {
                return false;
            }
        }
        return true;
    }
};