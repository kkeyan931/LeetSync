class Solution {
public:
    bool kahnAlgo(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> umap;
        vector<int> inDegree(numCourses);
        queue<int> q;

        for (auto& p : prerequisites) {
            umap[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < numCourses; ++i) {
            for (auto v : umap[i]) {
                inDegree[v]++;
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            count++;

            for (auto v : umap[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return count == numCourses;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return kahnAlgo(numCourses, prerequisites);
    }
};