// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxPath(int i, int j, int n, vector<vector<int>> &m, vector<vector<int>>& dp){
        if(j<0 || j>=n) return 0;
        if(i==n-1) return m[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j]=m[i][j]+max(maxPath(i+1, j, n, m, dp), max(maxPath(i+1, j-1, n, m, dp), maxPath(i+1, j+1, n, m, dp)));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int maxi=0;
        vector<vector<int>>dp(N, vector<int>(N, -1));
        for(int j=0; j<N; j++){
            maxi=max(maxi, maxPath(0, j, N,  Matrix, dp));
        }
        
        return maxi;
        
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends