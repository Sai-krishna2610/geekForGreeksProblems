class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
       int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> ans;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while (!q.empty()) {
            
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return ans;
    }
};