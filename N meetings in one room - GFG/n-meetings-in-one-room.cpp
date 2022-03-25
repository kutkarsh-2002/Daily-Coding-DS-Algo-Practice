// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool comp(pair<int, int>a, pair<int, int>b){
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        /*int me=*max_element(end, end+n);
        vector<bool>vis(me, false);
        int mCount=0;
        
        for(int i=0; i<n; i++){
            for(int j=end[i]-1; j>=start[i]; j--){
                if(vis[j]==true)
                continue;
                else{
                    vis[j]=true;
                    mCount++;
                    break;
                }
            }
        }
        
        return mCount;*/
        
        vector<pair<int, int>>v;
        
        for(int i=0; i<n; i++){
            v.push_back({start[i], end[i]});
        }
        
        sort(v.begin(), v.end(), comp);
        
        int mCount=1, prev=0;
        
        for(int i=1; i<n; i++){
            if(v[i].first>v[prev].second){
                mCount++;
                prev=i;
            }
        }
        
        return mCount;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends