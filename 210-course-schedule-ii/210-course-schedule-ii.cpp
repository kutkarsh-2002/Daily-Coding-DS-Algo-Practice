class Solution {
public:
    bool isCycle(int u, vector<int>&vis, vector<int>&dfsV, vector<int>adj[])
    {   vis[u]=1;
        dfsV[u]=1;
        
        for(auto x:adj[u]){
            if(vis[x]==0){
                if(isCycle(x, vis, dfsV, adj)) return true;
            }
            else if(vis[x]==1 && dfsV[x]==1) return true;
        }
     
        dfsV[u]=0;
     
     return false;
        
    }
    
    void dfs(int u, vector<int>&vis, stack<int>&st, vector<int>adj[])
    {
        vis[u]=1;
        
        for(auto x:adj[u]){
            if(vis[x]==0){
                dfs(x, vis, st, adj);
            }
        }
        
        st.push(u);
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>res;
        vector<int>adj[n];
        
        for(int i=0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        vector<int>vis(n, 0);
        vector<int>dfsV(n, 0);
        
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                if(isCycle(i, vis, dfsV, adj)) return res;
            }
        }
        
        stack<int>st;
        fill(vis.begin(), vis.end(), 0);
        
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                dfs(i, vis, st, adj);
            }
        }
        
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
    }
};