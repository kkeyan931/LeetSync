class Solution {
public:
    vector<int> kahnAlgo(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        queue<int> q;
        vector<int> inDegree(numCourses);

        for (int i = 0; i < numCourses; ++i) {
            for (auto toNode : adj[i]) {
                inDegree[toNode]++;
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            for (auto nextNode : adj[node]) {
                inDegree[nextNode]--;
                if (inDegree[nextNode] == 0) {
                    q.push(nextNode);
                }
            }
        }
        if (result.size() != numCourses) {
            return {};
        }
        return result;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        return kahnAlgo(numCourses, prerequisites);
    }
};