// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int V, int i, vector<int> adj[], vector<int>&v, bool visited[]){
        visited[i]=true;
        v.push_back(i);
        
        for(int x:adj[i]){
            if(visited[x]==false){
                dfs(V, x, adj, v, visited);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        bool visited[V+1];
        vector<int>res;
        for(int i=0; i<V; i++){
            visited[i]=false;
        }
        
        dfs(V, 0, adj, res, visited);
        
        return res;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends