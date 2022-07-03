class Solution {
public:
    
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]==1)
            return ;
        
        grid[i][j]=2;
        vis[i][j]=1;
        
        dfs(i-1, j, vis, grid);
        dfs(i, j-1, vis, grid);
        dfs(i, j+1, vis, grid);
        dfs(i+1, j, vis, grid);
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        int x, y;
        vector<vector<int>>vis(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1)
                {
                    x=i, y=j;
                    break;
                }
            }
        }
        
        dfs(x, y, vis, grid);
        
        
        int minflip=INT_MAX;
        
        vector<pair<int, int>>v1, v2;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                
                if(grid[i][j]==1){
                    v1.push_back({i, j}); 
                }
                else if(grid[i][j]==2){
                    v2.push_back({i, j}); 
                }
            }
        }
        
        for(int i=0; i<v1.size(); i++){
            
            for(int j=0; j<v2.size(); j++){
                
                minflip=min(minflip, abs(v1[i].first-v2[j].first)+abs(v1[i].second-v2[j].second)-1);
            }
        }
        
        return minflip;
    }
};