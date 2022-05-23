class Solution {
public:
    int TotalUpaths(int i, int j, int &m, int &n,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return 1;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int l, t;
        
        t=(i-1<0)?0:TotalUpaths(i-1, j, m, n, dp);
        l=(j-1<0)?0:TotalUpaths(i, j-1, m, n, dp);
        
        
        return dp[i][j]=l+t;
    }
    
    int uniquePaths(int m, int n) {
        
//         int dp[m][n];
        
//         for(int i=0; i<m; i++){
//             dp[i][0]=1;
//         }
//         for(int j=0; j<n; j++){
//             dp[0][j]=1;
//         }
        
//         for(int i=1; i<m; i++){
//             for(int j=1; j<n; j++){
//                 dp[i][j]=dp[i][j-1]+dp[i-1][j];
//             }
//         }
        
//         return dp[m-1][n-1];
        
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return TotalUpaths(m-1 ,n-1, m, n, dp);
    }
};