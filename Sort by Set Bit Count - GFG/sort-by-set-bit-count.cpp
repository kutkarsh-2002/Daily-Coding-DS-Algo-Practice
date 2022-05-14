// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Using Brian Kerningam's Algo to find the set bits in given integers
    
    int setBits(int n){
        int res=0;
        
        while(n>0){
            n=n&(n-1);
            res++;
        }
        //cout<<res<<endl;
        return res;
    }
    
    static bool cmp(pair<int, int>a, pair<int, int>b){
        return a.second>b.second;
    }
    
    void sortBySetBitCount(int arr[], int n)
    {
        vector<pair<int, int>>v;
        
        for(int i=0; i<n; i++){
            v.push_back({arr[i], setBits(arr[i])});
        }
        
        stable_sort(v.begin(), v.end(), cmp);
        
        fill(arr, arr+n, 0);
        int i=0;
        
        for(auto x:v){
            arr[i]=x.first;
            i++;
        }
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends