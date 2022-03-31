// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    
    /*void dfs(int node, int parent, vector<bool>&vis, vector<int>&tin, vector<int>&low, vector<int>adj[], int &timer, int &c, int &d, bool &flag)
    {
        vis[node]=true;
        tin[node]=low[node]=timer++;
        
        for(int it:adj[node]){
            if(it==parent)continue;
            
            if(vis[it]==false){
                dfs(it, node, vis, tin, low, adj, timer, c, d, flag);
                low[node]=min(low[node], low[it]);
                
            
                // if(low[it]>tin[node]){
                //     cout<<it<<" "<<node<<endl;
                    
                // }
                
                if(low[d]>tin[c]){
                    flag=true;
                    return;
                }
                
            }
            else{
                low[node]=min(low[node], tin[it]);
            }
            
        }
        
        
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool>vis(V, false);
        vector<int>tin(V);
        vector<int>low(V);
        
        
        int timer=0;
        bool flag=false;
        
        for(int i=0; i<V; i++){
            if(vis[i]==false){
                dfs(i, -1, vis, tin, low, adj, timer, c, d, flag);
            }
        }
        
        if(flag)
        return 1;
        
        return 0;
        
    }*/
    
    void dfs(int x, vector<bool>&vis, vector<int>adj[], int c, int d){
        vis[x]=true;
        for(auto it:adj[x]){
            if(!vis[it] && (x!=c || it!=d)){
                dfs(it, vis, adj, c, d);
            }
        }
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool>vis(V, false);
        dfs(c, vis,  adj, c, d);
        return !vis[d];
        
    }
    
    
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends