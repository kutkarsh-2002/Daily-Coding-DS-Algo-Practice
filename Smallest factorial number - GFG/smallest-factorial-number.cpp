// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    
        int trail(int n){
            int res=0;
            
            for(int i=5; i<=n; i=i*5){
                res+=n/i;
            }
            return res;
        }
        
        int findNum(int n)
        {
        //complete the function here
        int low=1, high=5*n, mid;
        
        while(low<=high){
            mid=(low+high)/2;
            
            if(trail(mid)==n && mid%5==0){
                return mid;
            }
            else if(trail(mid)<n){
                low=mid+1;
            }
            else
            high=mid-1;
        }
        
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends