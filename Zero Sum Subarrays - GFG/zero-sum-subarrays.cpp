// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    /*long long countSubSet(vector<ll>& arr, int n , int sum){
        long long dp[n+1][sum+1];
        
        for(int i=0; i<=n; i++){
            dp[i][0]=1;
        }
        
        for(int j=1; j<=sum; j++){
            dp[0][j]=0;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        
        
        return dp[n][sum];
    }*/
    
    ll findSubarray(vector<ll> arr, int n ) {
        //This is based on prefixsum
        
        unordered_map<int, int>mp;
        long long psum=0, ans=0;
        mp.insert({0,1});
        for(int i=0; i<n; i++){
            psum+=arr[i];
            
            if(mp.find(psum)!=mp.end()){
                ans+=mp[psum];
                mp[psum]++;
            }else{
                
                mp.insert({psum, 1});
            }
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends