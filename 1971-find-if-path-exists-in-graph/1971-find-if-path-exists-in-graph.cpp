class Solution {
public:
    
    bool dfs(int u, int dst, vector<int>&vis, vector<int>adj[]){
        
        if(u==dst)
            return true;
        
        vis[u]=1;
        
        
        for(auto v: adj[u]){
           
            if(vis[v]==0){
                if(dfs(v, dst, vis, adj)) return true;
            }
            
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        vector<int>adj[n];
        
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int>vis(n, 0);
        
        return dfs(src, dst, vis, adj);
    }
};