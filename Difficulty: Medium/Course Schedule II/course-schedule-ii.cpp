class Solution {
  public:
  
    vector<int> topologicalSort(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree) {
        
        queue<int> q;
        vector<int> ans;
        int count = 0;
        
        for (int i=0; i<n; i++) {
            
            if (indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
                count++;
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int& v : adj[u]) {
                indegree[v]--;
                
                if (indegree[v] == 0) {
                    q.push(v);
                    ans.push_back(v);
                    count++;
                }
            }
        }
        if (count == n) return ans;
        return {};
    }
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        
        for (auto& pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];
            
            adj[v].push_back(u);
            
            indegree[u]++;
        }
        
        return topologicalSort(adj, n, indegree);
    }
};