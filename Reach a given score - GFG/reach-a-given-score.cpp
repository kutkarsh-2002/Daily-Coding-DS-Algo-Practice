// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function


long long int findOp(int x, long long int target,  vector<long long int>&arr, vector<vector<long long int >>&dp){
    
    if(x<0 || target<0) return 0;
    if(target==0) return 1;
    
    if(dp[target][x]!=-1) return dp[target][x];
    
    long long int take=0;
    if(arr[x]<=target){
        take=findOp(x, target-arr[x], arr, dp);
    }
    long long int nottake=findOp(x-1, target, arr, dp);
    
    return dp[target][x]=take+nottake;
}

long long int count(long long int n)
{
	vector<vector<long long int>>dp(n+1, vector<long long int>(3, -1));
	vector<long long int>arr={3, 5, 10};
	return findOp(2, n, arr, dp);
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends