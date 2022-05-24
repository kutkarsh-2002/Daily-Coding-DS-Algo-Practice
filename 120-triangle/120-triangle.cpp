class Solution {
public:
    int miniPathTriangle(int i, int j, int &n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i==n-1)
            return triangle[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]=triangle[i][j]+min(miniPathTriangle(i+1, j, n, triangle, dp), miniPathTriangle(i+1, j+1, n, triangle, dp));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        
        return miniPathTriangle(0, 0, n, triangle, dp);
    }
};