// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool cycledet(int u, vector<int>&vis, vector<int>adj[]){
        queue<pair<int, int>>q;
        q.push({u, -1});
        vis[u]=1;
        
        while(!q.empty()){
            pair<int, int> node=q.front();
            q.pop();
            
            for(auto x: adj[node.first]){
                if(vis[x]==1 && x!=node.second){
                    return true;
                }
                else if(vis[x]!=1){
                    q.push({x, node.first});
                    vis[x]=1;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
     
        vector<int>vis(V, 0);
        
        for(int i=0; i<V; i++){
            if(vis[i]!=1){
                if(cycledet(i, vis, adj)) return true;
            }
        }
        
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends