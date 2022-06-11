class Solution {
public:
    
    long long dfs(int i, int j , int p, vector<vector<int>>& m, vector<vector<long long>>&dp)
    {
       if(i<0 || i>=m.size() || j<0 || j>=m[0].size() || m[i][j]<=p)
            return 0;
        
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        long long u=dfs(i-1, j, m[i][j], m, dp);
        long long d=dfs(i+1, j, m[i][j], m, dp);
        long long l=dfs(i, j-1, m[i][j], m, dp);
        long long r=dfs(i, j+1, m[i][j], m, dp);
        
        
        return dp[i][j]=max({u, d, l, r})+1;
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        long long res=0;
        vector<vector<long long>>dp(matrix.size(), vector<long long>(matrix[0].size(), -1));
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                res=max(res, dfs(i, j, -1, matrix, dp));
            }
        }
        
        return res;
    }
    
    
};