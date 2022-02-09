class Solution {
public:
    
    int LCS(string s1, string s2){
        int n=s1.size(), m=s2.size();
        int dp[n+1][m+1];
        
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
        }
        for(int j=1; j<=m; j++){
            dp[0][j]=0;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        
        int n=word1.size();
        int m=word2.size();
        int count=0;
        count=LCS(word1, word2);
        cout<<count;
        int res=(n-count)+(m-count);
        
        return res;
        
    }
};