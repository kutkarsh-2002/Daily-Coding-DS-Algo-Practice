class Solution {
public:
    void collectGold(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>&visited, int&sum, int&maxSum){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j]==true || grid[i][j]==0){
            return ;
        }
        
        visited[i][j]=true;
        sum+=grid[i][j];
        
        maxSum=max(maxSum, sum);
        
        collectGold(grid, i-1, j, visited, sum, maxSum); //up
        collectGold(grid, i, j+1, visited, sum, maxSum); //right
        collectGold(grid, i, j-1, visited, sum, maxSum); //left
        collectGold(grid, i+1, j, visited, sum, maxSum); //down
        
        visited[i][j]=false;
        sum-=grid[i][j]; //backtracking
    }
    
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int n=grid.size(), m=grid[0].size();
        int maxSum=INT_MIN;
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(grid[i][j]!=0 && visited[i][j]==false){
                    
                    int sum=0;
                    collectGold(grid, i, j, visited, sum, maxSum);
                    
                }
                
            }
        }
        
        return (maxSum==INT_MIN)?0:maxSum;
    }
};