class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node, vector<vector<int>>& result,
             vector<int>& temp) {

        if (node == graph.size() - 1) {
            result.push_back(temp);
            return;
        }
        for (auto nextNode : graph[node]) {
            temp.push_back(nextNode);
            dfs(graph, nextNode, result, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> doDFS(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> temp;
        temp.push_back(0);
        dfs(graph, 0, result, temp);

        return result;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        return doDFS(graph);
    }
};