class Solution {
public:
    
    void dfs(int u, int&count, vector<int>&vis, vector<int>adj[])
    {   vis[u]=1;
        for(auto v:adj[u]){
            if(vis[abs(v)]!=1){
                
                if(v>0){
                    count++;
                }
                dfs(abs(v), count, vis, adj);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        int count=0;
        vector<int>vis(n, 0);
        vector<int>adj[n];
        
        for(int i=0; i<connections.size(); i++){
            // if(connections[i][1]==0){
            //     vis[connections[i][0]]=1;
            // }
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(-connections[i][0]);
        }
        // vis[0]=1;
        
        
        for(int i=0; i<n; i++){
            // if(adj[i].size()>0){
            //     dfs(i, count, vis, adj);
            // }
            dfs(i, count, vis, adj);
        }
        
        return count;
    }
};