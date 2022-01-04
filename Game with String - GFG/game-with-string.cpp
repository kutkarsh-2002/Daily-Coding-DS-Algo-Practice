// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
         unordered_map<char,int> m;
        int sum=0;
        for(int i=0;i<s.length();i++)
         m[s[i]]++;
         priority_queue<pair<int,char>> pq;
         
         for(auto i=m.begin();i!=m.end();i++)
         {
             pq.push({i->second,i->first});
             
         }
         
        while(!pq.empty() && k--)
        {
           pair<int,char> p= pq.top();
           pq.pop();
           m[p.second]--;
           pq.push({m[p.second],p.second});
            
            
            
        }
         
         while(!pq.empty())
         {
             sum=sum+pq.top().first*pq.top().first;
             pq.pop();
         }
        return sum; 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends