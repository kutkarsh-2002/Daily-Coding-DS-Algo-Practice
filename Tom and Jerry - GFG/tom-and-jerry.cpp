//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int numsGame(int n) {
        // code here
        // bool flag=false;
        
        // while(n>1){
        //     n=n-1;
        //     flag=!flag;
        // }
        
        // return (flag)?1:0;
        
        if(n%2==0) return 1;
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.numsGame(N) << endl;
    }
    return 0;
}
// } Driver Code Ends