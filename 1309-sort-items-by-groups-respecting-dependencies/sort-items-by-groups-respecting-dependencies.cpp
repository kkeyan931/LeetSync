class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> inDegree(n, 0);

        for (int node = 0; node < n; node++) {
            for (auto nextNode : graph[node]) {
                inDegree[nextNode]++;
            }
        }

        queue<int> queue;

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                queue.push(i);
            }
        }

        while (!queue.empty()) {

            int node = queue.front();
            queue.pop();
            result.push_back(node);

            for (auto nextNode : graph[node]) {
                inDegree[nextNode]--;

                if (inDegree[nextNode] == 0) {
                    queue.push(nextNode);
                }
            }
        }

        if (result.size() != n) {
            return {};
        }
        return result;
    }
    vector<int> sortItems(int n, int m, vector<int>& group,
                          vector<vector<int>>& beforeItems) {

        int groupId = m;

        for (int index = 0; index < group.size(); ++index) {
            if (group[index] == -1) {
                group[index] = groupId;
                groupId++;
            }
        }

        vector<vector<int>> itemGraph(n);
        vector<vector<int>> groupGraph(groupId);

        for (int currItem = 0; currItem < beforeItems.size(); ++currItem) {
            for (auto beforeItem : beforeItems[currItem]) {
                itemGraph[beforeItem].push_back(currItem);

                if (group[beforeItem] != group[currItem]) {
                    groupGraph[group[beforeItem]].push_back(group[currItem]);
                }
            }
        }

        vector<int> itemTopoSort = topoSort(itemGraph);
        vector<int> groupTopoSort = topoSort(groupGraph);

        if (itemTopoSort.empty() || groupTopoSort.empty()) {
            return {};
        }

        unordered_map<int, vector<int>> itemOrderMap;

        // group item by groupId
        for (auto item : itemTopoSort) {
            itemOrderMap[group[item]].push_back(item);
        }

        vector<int> result(n);
        int index = 0;
        for (auto group : groupTopoSort) {
            for (auto item : itemOrderMap[group]) {
                result[index++] = item;
            }
        }
        return result;
    }
};