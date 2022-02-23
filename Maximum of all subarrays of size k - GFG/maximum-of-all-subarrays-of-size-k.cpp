// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        /*
        vector<int>v;
        queue<int>pq;
        
        
        for(int i=0; i<k; i++){
            pq.push(arr[i]);
            
        }
        
        
        for(int i=k; i<n; i++){
            queue<int>q;
            int mx=INT_MIN;
            while(!pq.empty()){
                q.push(pq.front());
                mx=max(mx, pq.front());
                pq.pop();
            }
            
            q.pop();
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
            v.push_back(mx);
            pq.push(arr[i]);
        }
        int mx=INT_MIN;
        while(!pq.empty()){
            mx=max(mx, pq.front());
            pq.pop();
        }
            
        v.push_back(mx);
        return v;*/
        
        deque<int>dq;
        vector<int>res;
        int i=0, j=0;
        
        while(i<=n-k && j<n)
        {
            
            if(dq.size()==0){
                dq.push_back(arr[j]);
            }
            else if(dq.back()>arr[j]){
                dq.push_back(arr[j]);
            }
            else{
                
                while(!dq.empty() && dq.back()<arr[j]){
                    dq.pop_back();
                }
                
                dq.push_back(arr[j]);
            }
            
            if(j-i+1==k){
                
                res.push_back(dq.front());
                
                if(arr[i]==dq.front()){
                    dq.pop_front();
                }
                
                i++;
            }
            
            j++;
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends