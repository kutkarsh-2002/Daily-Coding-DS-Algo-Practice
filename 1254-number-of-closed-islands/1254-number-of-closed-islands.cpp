class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==1)
            return ;
        
        
        grid[i][j]=1;
        
        dfs(i-1, j, grid);
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);
        dfs(i+1, j, grid);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        //vector<vector<int>>vis(grid.size(), vector<int>(grid[0].size(), 0));
        int count=0;
        
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==0 && (i*j==0 || (i==grid.size()-1) || (j==grid[0].size()-1))){
                    dfs(i, j, grid); 
                }
            }
        }
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==0){
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        
        return count;
    }
};