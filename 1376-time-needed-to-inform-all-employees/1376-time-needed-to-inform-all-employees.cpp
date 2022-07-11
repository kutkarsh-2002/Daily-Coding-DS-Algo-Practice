class Solution {
public:
    void dfs(int u, int p, vector<int>&time, vector<int>& informTime, vector<int>adj[])
    {   
        if(p==-1){
            time[u]=informTime[u];
        }else{
            time[u]=time[p]+informTime[u];
        }
        
        for(auto v:adj[u]){
            dfs(v, u, time, informTime, adj);
        }
        
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int>time(n, 0);
        
        vector<int>adj[n];
        
        for(int i=0; i<n; i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }
        
        dfs(headID, -1, time, informTime, adj);
        
        return *max_element(time.begin(), time.end());
    }
};