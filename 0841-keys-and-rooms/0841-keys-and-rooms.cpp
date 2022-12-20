class Solution {
public:
    void dfs(int u, vector<int>&vis, vector<vector<int>>& rooms){
        vis[u]=1;
        
        for(auto v:rooms[u]){
            if(vis[v]==0){
                dfs(v, vis, rooms);
            }
            
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        
        vector<int>vis(n, 0);
        
        dfs(0, vis, rooms);
        
        for(int i=0; i<n; i++){
            if(vis[i]==0)
                return false;
        }
        
        return true;
    }
};