// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        sort(arr, arr+n);
        int *ans=new int[2];
        map<int, int>mp;
        
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        for(auto x: mp){
            if(x.second>1){
                ans[0]=x.first;
            }
            
        }
        
        for(int i=0; i<n; i++){
            if(mp.find(i+1)==mp.end()){
                ans[1]=i+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends