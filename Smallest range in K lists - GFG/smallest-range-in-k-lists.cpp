// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
typedef pair<int, pair<int, int>> pi;
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {   
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        int mn = INT_MAX, mx = INT_MIN, range = INT_MAX;
        for (int i=0; i<k; i++) {
            pq.push({KSortedArray[i][0], {i, 0}});
            mn = min(mn, KSortedArray[i][0]);
            mx = max(mx, KSortedArray[i][0]);
        }
        int a = mn, b = mx;
        while (!pq.empty()) {
            pi curr = pq.top();
            pq.pop();
            //cout<<curr.first<<" "<<curr.second.first<<" "<<curr.second.second<<endl;
            if (curr.second.second + 1 < n) {
                int r = curr.second.first, c = curr.second.second + 1;
                pq.push({KSortedArray[r][c], {r, c}});
                mn = pq.top().first;
                mx = max(mx, KSortedArray[r][c]);
                if (b-a > mx-mn) {
                    a = mn;
                    b = mx;
                }
            } else {
                break;
            }
        }
        return {a, b};
         
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends