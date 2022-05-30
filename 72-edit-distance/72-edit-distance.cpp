class Solution {
public:
//     int minedit(int i, int j, string& s, string& t, vector<vector<int>>dp){
//     if(i<0) return j+1;
//     if(j<0) return i+1;
    
//     if(dp[i][j]!=-1) return dp[i][j];
    
//     if(s[i]==t[j])
//         return dp[i][j]=0+minedit(i-1, j-1, s, t, dp);
//     else
//         return dp[i][j]=1+min(minedit(i-1, j-1, s, t, dp), min(minedit(i, j-1, s, t, dp), minedit(i-1, j, s, t, dp)));
// } 

    int minDistance(string s, string t) {
        int n=s.size(), m=t.size();
        
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                
                if(i==0 && j==0){
                    dp[i][j]=0;
                }
                else if(i==0){
                    dp[i][j]=j;
                }
                else if(j==0){
                    dp[i][j]=i;
                }
                else if(s[i-1]==t[j-1]){
                    //if both character are same then no operation will be required.
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    // if both character is diffrenet try to find the min operation from all remove, insert, and delete
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1]));
                }    
            }
        }
        
        return dp[n][m];
        
        // int n=s.size();
        // int m=t.size();
        // vector<vector<int>>dp(n, vector<int>(m, -1));
        // return minedit(n-1, m-1, s, t, dp);
    }
};