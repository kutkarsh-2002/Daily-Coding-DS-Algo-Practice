// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  
    int editDistance(string word1, string word2) {
       int n=word1.size(), m=word2.size();
        
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
                else if(word1[i-1]==word2[j-1]){
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
       
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends