class Solution {
public:
    void dfs(int u, vector<int>&vis, vector<int>adj[])
    {
        vis[u]=1;
        
        for(auto v:adj[u]){
            if(vis[v]==0){
                dfs(v, vis, adj);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<int>adj[n];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        
        int ans=0;
        vector<int>vis(n, 0);
        
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                dfs(i, vis, adj);
                ans++;
            }
        }
        
        return ans;
    }
};