class Solution {
public:
    
    void markIsland(vector<vector<char>>&grid, int i, int j, int rows, int cols){
        if(i<0 || j<0 || i>=rows || j>=cols || grid[i][j]!='1'){
            return;
        }
        
        if(grid[i][j]=='1'){
            grid[i][j]='2';
        }
        markIsland(grid, i+1, j, rows, cols);
        markIsland(grid, i, j+1, rows, cols);
        markIsland(grid, i-1, j, rows, cols);
        markIsland(grid, i, j-1, rows, cols);
        
    }
    int numIslands(vector<vector<char>>& grid) {
       
        //For fast I/O 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int countIsland=0;
        int rows=grid.size();
        int cols=grid[0].size();
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]=='1'){
                    markIsland(grid, i, j, rows, cols);
                    countIsland++;
                }
            }
        }
        
        return countIsland;
       
    }
};