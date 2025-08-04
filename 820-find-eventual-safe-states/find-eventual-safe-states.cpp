class Solution {
   public:
    bool dfs(int node, vector<bool> &path, vector<bool> &visited,
             vector<bool> &check, vector<vector<int>> &adj) {
        visited[node] = true;
        path[node] = true;

        check[node] = false;

        for (auto nextNode : adj[node]) {
            if (path[nextNode]) {
                return true;
            }
            if (!visited[nextNode]) {
                if (dfs(nextNode, path, visited, check, adj)) {
                    return true;
                }
            }
        }
        check[node] = true;

        path[node] = false;
        return false;
    }
    vector<int> doDFS(int N, vector<vector<int>> &adj) {
        vector<bool> visited(N, false);
        vector<bool> path(N, false);

        vector<bool> check(N, false);
        vector<int> result;

        for (int node = 0; node < N; ++node) {
            if (!visited[node]) {
                dfs(node, path, visited, check, adj);
            }
        }
        for (int node = 0; node < N; ++node) {
            if (check[node]) {
                result.push_back(node);
            }
        }
        return result;
    }

    vector<int> topoSort(int n, vector<vector<int>> &adj) {
	    
	    vector<int> inDegree(n, 0);
	    
		for (int i = 0; i < n; i++) {
			for(auto it : adj[i]) {
			    inDegree[it]++;
			}
		}
        vector<int> ans;
	    
	    queue<int> q;
	    
	    for(int i=0; i<n; i++) {
	        if(inDegree[i] == 0) q.push(i);
	    }
	    while(!q.empty()) {
	        
	        int node = q.front();
	        
	        ans.push_back(node);
	        q.pop();
	        for(auto it : adj[node]) {
	            inDegree[it]--;
	            if(inDegree[it] == 0) q.push(it);
	        }
	    }
	    return ans;
    }
    vector<int> doBFS(int n, vector<vector<int>> &adj) {
	    vector<vector<int>> adjRev(n);
	    // Reversing the edges
	    for (int i = 0; i < n; i++) {
			// i -> it, it-> i
			for (auto it : adj[i]) {
			    // Add the edge to reversed graph
				adjRev[it].push_back(i);
			}
		}
		
	    vector<int> result = topoSort(n, adjRev);
	    
	    sort(result.begin(), result.end());
	    
	    return result;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &adj) {
        // return doDFS(adj.size(), adj);
        return doBFS(adj.size(), adj);
    }
};