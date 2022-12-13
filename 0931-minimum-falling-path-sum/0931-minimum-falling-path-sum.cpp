class Solution {
public:

    int minfallsum(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i==matrix.size()-1) return matrix[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        if(j>0 && j<matrix[0].size()-1){
            return dp[i][j]=matrix[i][j]+min({minfallsum(i+1, j-1, matrix, dp), minfallsum(i+1, j, matrix, dp), minfallsum(i+1, j+1, matrix, dp)});
        }
        else if(j==matrix[0].size()-1){
            return dp[i][j]=matrix[i][j]+min(minfallsum(i+1, j-1, matrix, dp), minfallsum(i+1, j, matrix, dp));
        }
        else{
            return dp[i][j]=matrix[i][j]+min(minfallsum(i+1, j, matrix, dp), minfallsum(i+1, j+1, matrix, dp));
        }

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int res=INT_MAX;

        for(int j=0; j<matrix[0].size(); j++){
            vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(), -1));
            res=min(res, minfallsum(0, j, matrix, dp));
        }

    return res;

    }
};