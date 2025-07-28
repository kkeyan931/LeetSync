class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ul_u = findParent(u);
        int ul_v = findParent(v);
        if (ul_u == ul_v)
            return;

        if (size[ul_v] < size[ul_u]) {
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int size = accounts.size();
        DisjointSet djs(size);

        unordered_map<string, int> emailMap;

        for (int i = 0; i < size; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (emailMap.find(accounts[i][j]) != emailMap.end()) {
                    djs.unionBySize(i, emailMap[accounts[i][j]]);
                } else {
                    emailMap[accounts[i][j]] = i;
                }
            }
        }
        vector<set<string>> mails(size);

        for (int i = 0; i < size; ++i) {
            int ul_p = djs.findParent(i);
            for (int j = 1; j < accounts[i].size(); ++j) {
                mails[ul_p].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> result;
        for (int i = 0; i < size; ++i) {
            if (mails[i].size() == 0)
                continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (auto& email : mails[i]) {
                temp.push_back(email);
            }
            result.push_back(temp);
        }
        return result;
    }
};
