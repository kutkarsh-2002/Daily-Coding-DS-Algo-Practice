class Solution {
public:
    
    bool checker(int i, int j, int k, string& s1, string&s2, string&s3, vector<vector<int>>&dp)
    {   if(k>=s3.size()) return 1;
     
        if(dp[i][j]!=-1) return dp[i][j];
        
            
        if(i<s1.size() && j<s2.size() && s1[i]==s3[k] && s2[j]==s3[k])
            return dp[i][j]=checker(i+1, j, k+1, s1, s2, s3, dp) || checker(i, j+1, k+1, s1, s2, s3, dp);
        else if(i<s1.size() && s1[i]==s3[k])
            return dp[i][j]=checker(i+1,j, k+1, s1, s2, s3, dp);
        else if(j<s2.size() && s2[j]==s3[k])
            return dp[i][j]=checker(i,j+1, k+1, s1, s2, s3, dp);
        
        else{
            return dp[i][j]=0;
        }
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(), m=s2.size(), k=s3.size();
        
        if(n+m!=k) return 0;
        vector<vector<int>>dp(201, vector<int>(201, -1));
        
        return checker(0, 0, 0, s1, s2, s3, dp);
    }
};