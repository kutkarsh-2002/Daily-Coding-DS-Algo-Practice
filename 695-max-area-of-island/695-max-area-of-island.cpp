class Solution {
public:
    void dfs(int i, int j, int &temp, vector<vector<int>>&vis, vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]==1)
            return ;
        
        vis[i][j]=1;
        temp++;
        
        dfs(i-1, j, temp, vis, grid);
        dfs(i, j-1, temp, vis, grid);
        dfs(i, j+1, temp, vis, grid);
        dfs(i+1, j, temp, vis, grid);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        vector<vector<int>>vis(grid.size(), vector<int>(grid[0].size(), 0));
        
        int mxArea=0, temp=0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    dfs(i, j, temp, vis, grid);
                    mxArea=max(mxArea, temp);
                    temp=0;
                }
            }
        }
        
        return mxArea;
    }
};