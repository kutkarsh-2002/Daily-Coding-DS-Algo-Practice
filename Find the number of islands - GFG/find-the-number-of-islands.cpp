// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void markIsland(vector<vector<char>>&grid, int i, int j, int rows, int cols){
        if(i<0 || j<0 || i>=rows || j>=cols || grid[i][j]!='1'){
            return;
        }
        
        if(grid[i][j]=='1'){
            grid[i][j]='2';
        }
        markIsland(grid, i+1, j, rows, cols); //down
        markIsland(grid, i, j+1, rows, cols); //right
        markIsland(grid, i-1, j, rows, cols); //Up
        markIsland(grid, i, j-1, rows, cols); //left
        markIsland(grid, i-1, j-1, rows, cols); //diagonal 
        markIsland(grid, i+1, j+1, rows, cols);
        markIsland(grid, i-1, j+1, rows, cols);
        markIsland(grid, i+1, j-1, rows, cols);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
       
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

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends