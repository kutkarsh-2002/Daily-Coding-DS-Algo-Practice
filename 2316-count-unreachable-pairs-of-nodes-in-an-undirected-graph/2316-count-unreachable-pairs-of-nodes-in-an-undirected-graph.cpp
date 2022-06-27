class Solution {
public:
    
    void dfs(int u, long long &count, vector<int>&vis, vector<int>adj[]){
        vis[u]=1;
        count++;
        
        for(auto v:adj[u]){
            if(vis[v]!=1){
                dfs(v, count, vis, adj);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>vis(n, 0);
        vector<int>adj[n];
        long long ans=0;
        
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
        }
        
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                long long count=0;
                dfs(i, count, vis, adj);
                ans+=(count*(n-count));
                
            }
        }
        
        return ans/2;
    }
};