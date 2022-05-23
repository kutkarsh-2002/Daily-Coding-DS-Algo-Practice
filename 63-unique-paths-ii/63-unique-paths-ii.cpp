class Solution {
public:
    int countPaths(int i, int j, vector< vector< int> > &dp, vector< vector< int> > &mat){
        if(i>=0 && j>=0 && mat[i][j]==1)
            return 0;

        if(i==0 && j==0)
            return 1;
        
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        int t=countPaths(i-1, j, dp, mat);
        int l=countPaths(i, j-1, dp, mat);

        return dp[i][j]=t+l;
    
}
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();
        
//         if(m==0||n==0) return 0;
        
//         int dp[m][n];
//         memset(dp, 0, sizeof(dp));
        
//         for(int i=0; i<m; i++){
//             if(obstacleGrid[i][0]!=1){
//                 dp[i][0]=1;
//             }else{
//                 break;
//             }
//         }
//         for(int j=0; j<n; j++){
//             if(obstacleGrid[0][j]!=1){
//                 dp[0][j]=1;
//             }else{
//                 break;
//             }
//         }
        
//         for(int i=1; i<m; i++){
//             for(int j=1; j<n; j++){
//                 if(obstacleGrid[i][j]==0){
//                     dp[i][j]=dp[i][j-1]+dp[i-1][j];
//                 }
//             }
//         }
        
        
//         return dp[m-1][n-1];
        
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return countPaths(n-1, m-1, dp, obstacleGrid);
        
    }
};