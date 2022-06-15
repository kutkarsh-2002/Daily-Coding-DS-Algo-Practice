class Solution {
public:
    bool detcycle(int u, vector<int>&dfsV, vector<int>&vis, vector<int>adj[])
    {
        vis[u]=1;
        dfsV[u]=1;
        
        for(auto v:adj[u])
        {
            if(vis[v]==0){
                if(detcycle(v, dfsV, vis, adj)) return true;
            }
            else if(vis[v]==1 && dfsV[v]==1) return true;
        }
        
        dfsV[u]=0;
        
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        
        for(int i=0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        vector<int>vis(n,0);
        vector<int>dfsV(n, 0);
        
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                if(detcycle(i, dfsV, vis, adj)) return false;
            }
        }
        
        return true;
    }
};