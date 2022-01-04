// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    
    /*
    
    vector<long long>v;
    for(long long i=0; i<N-K+1; i++){
        long long j=i;
        long long size=K;
        while(size--){
            if(A[j]<0){
                v.push_back(A[j]);
                break;
            }else if(A[j]>0 && size==0){
                v.push_back(0);
            }
            else{
                j++;
            }
        }
    }
    
    return v;
       
       */
       /*Efficient Solution*/
       
       vector<long long>v;
       queue<long long>q;
       long long i=0;
       for(; i<K; i++){
           if(A[i]<0){
               q.push(i);
           }
       }
       for(; i<N; i++){
           
           if(q.empty()==false){
               v.push_back(A[q.front()]);
           }else{
               v.push_back(0);
           }
           
           while(q.empty()==false && q.front()<i-K+1){
               q.pop();
           }
           
           if(A[i]<0){
               q.push(i);
           }
           
       }
       if(q.empty()==false){
           v.push_back(A[q.front()]);
       }else{
           v.push_back(0);
       }
       
       return v;
       
 }