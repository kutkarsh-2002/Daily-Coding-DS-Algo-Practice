class Solution {
public:
    
    void dfs(int i, int j, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return ;
        
        grid[i][j]=0;
        
        
        dfs(i-1, j, grid);
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);
        dfs(i+1, j, grid);
    }
    
    void dfs2(int i, int j, int &count, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return ;
        
        grid[i][j]=0;
        count++;
        
        
        dfs2(i-1, j, count, grid);
        dfs2(i, j-1, count, grid);
        dfs2(i, j+1, count, grid);
        dfs2(i+1, j, count, grid);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if((i*j==0 || i==grid.size()-1 || j==grid[0].size()-1) && grid[i][j]==1){
                    dfs(i, j, grid);
                }
            }
        }
        
        int count=0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    dfs2(i, j, count, grid);
                }
            }
        }
        
        return count;
    }
};