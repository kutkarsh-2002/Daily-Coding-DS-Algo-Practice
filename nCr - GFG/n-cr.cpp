// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int m=1e9+7;
int find(int n, int r, vector<vector<int>> &dp){
      if(n<r)
        return 0;
      
      if(r==1)
        return dp[n][r]=n;
      
      if(n==r || r==0)
        return dp[n][r]=1;
        
    if(dp[n][r]!=-1)
        return dp[n][r];    
    
      return dp[n][r]=(find(n-1, r, dp)%m+find(n-1, r-1, dp)%m)%m;
}
    int nCr(int n, int r){
        // code here
    //   int dp[1001][1001];
    vector<vector<int>> v(n+1,vector<int> (r+1,-1));
    //   memset(dp, -1, sizeof(dp));--
      
      return find(n, r, v);
      
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends