// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool isCycle(int u, vector<int>&vis, vector<int>&dfsV, vector<int> adj[]){
        vis[u]=1;
        dfsV[u]=1;
        
        for(auto x: adj[u]){
            if(vis[x]==0){
                if(isCycle(x, vis, dfsV, adj)) return true;
            }
            else if(vis[x]==1 && dfsV[x]==1) return true;
        
        }
        
         dfsV[u]=0;
         
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
       vector<int>vis(V, 0);
       vector<int>dfsV(V, 0);
       
       for(int i=0; i<V; i++){
           if(vis[i]==0){
               if(isCycle(i, vis, dfsV, adj)) return true;
           }
       }
       
       return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends