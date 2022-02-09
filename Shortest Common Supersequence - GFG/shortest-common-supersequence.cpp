// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int LCS(string s, string t, int n, int m) {
        
        int dp[n+1][m+1];
        
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
        }
        for(int j=1; j<=m; j++){
            dp[0][j]=0;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                
                if(s[i-1]==t[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        
        int res=LCS(X, Y, m, n);
        
        
        return (n+m-res);
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends