// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  
  bool backtrack(int nums[], int n, vector<int>visited, int target, int curr_sum, int i, int k) {
		if (k == 1) return true;

		if (curr_sum == target) return backtrack(nums, n, visited, target, 0, 0, k-1);

		for (int j = i; j < n; j++) {
			if (visited[j] || curr_sum + nums[j] > target) continue;

			visited[j] = true;
			if (backtrack(nums, n, visited, target, curr_sum + nums[j], j+1, k)) return true;
			visited[j] = false;
		}

		return false;
	}
    
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=a[i];
        }  
        
        if(n<k || sum%k){
            return false;
        }
        if(k==1){
            return true;
        }
        
        vector<int>visited(n, false);
        
        return backtrack(a, n, visited, sum / k, 0, 0, k);
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
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends