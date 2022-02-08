// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long dp[1001][1001];
    int m=1e9+7;
    /*You are required to complete below method */
    long long count(int i, int j, string &s){
        if(i>j)
            return 0;
        if(i==j)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==s[j])
          return  dp[i][j]=(count(i+1, j, s)+count(i, j-1, s)+1)%m;
        
        else
          return  dp[i][j]=(m+count(i+1, j, s)+count(i, j-1, s)-count(i+1, j-1, s))%m;
    }
    long long int  countPS(string str)
    {
        int n=str.size();
        memset(dp, -1, sizeof(dp));
        
        return count(0, n-1, str);
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends