// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
   bool check(int i, int target, int arr [], vector<vector<int>>&dp){
    if(target==0) return true;

    if(i==0) return (arr[0]==target);

    if(dp[i][target]!=-1) return dp[i][target];

    bool taken=false, nottaken;
    if(arr[i]<=target)
        taken=check(i-1, target-arr[i], arr, dp);

    nottaken=check(i-1, target, arr, dp);

    return dp[i][target]=taken || nottaken;

}  

	int minDifference(int arr[], int n)  { 
	    
	    int Tsum=0;
        
        for(int i=0; i<n; i++){
            Tsum+=arr[i];
        }
        
        int k=Tsum/2;
        
        vector<vector<int>>dp(n, vector<int>(k+1, -1));
        
        int ans=1e9;
        
        for(int s1=0; s1<=k; s1++){
            if(check(n-1, s1, arr, dp))
            {  
                ans=min(ans, abs((Tsum-s1)-s1));
            }
           
        }
        
        return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends