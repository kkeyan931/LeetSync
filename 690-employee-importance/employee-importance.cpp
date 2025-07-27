/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int sum = 0;
    void dfs(int node, unordered_map<int, Employee*> &graph) {
        sum += graph[node]->importance;
        for(auto id : graph[node]->subordinates) {
            dfs(id, graph);
        }
    }
    int doDFS(int node, unordered_map<int, Employee*> &graph) {
        dfs(node, graph);
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> graph;

        for(auto emp : employees) {
            graph[emp->id] = emp;
        }
        return doDFS(id, graph);
    }
};