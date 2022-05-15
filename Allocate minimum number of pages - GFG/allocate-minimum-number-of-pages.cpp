// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool isallocationPossible(int A[], int N, int M, long long barrier){
        
        long long pages=0, allocatedS=1;
        
        for(int i=0; i<N; i++){
            if(A[i]>barrier)
            return false;
            
            if(pages+A[i]>barrier){
                allocatedS+=1;
                pages=A[i];
            }else{
                pages+=A[i];
            }
        }
        
        return (allocatedS>M)?false:true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        long long low, high, mid, res=-1;
        
        //To find the space search
        for(int i=0; i<N; i++){
    
            high+=A[i];
            low=min(low, (long long)A[i]);
        }
        
        while(low<=high){
            mid=(low+high)>>1;
            
            if(isallocationPossible(A, N, M, mid)){
                res=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
            
        }
        
        return low;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends