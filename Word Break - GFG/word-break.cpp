// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int dp[1110];
    
    int wordFind(string s, int pos, unordered_set<string>&st){
        
        if(pos==s.size())
            return true;
        
        if(dp[pos]!=-1){
            return dp[pos];
        }
        
        for(int i=pos; i<s.size(); i++){
            if(st.find(s.substr(pos, i-pos+1))!=st.end() && wordFind(s, i+1, st)){
                dp[pos]=1;
                return 1;
            }
        }
        
        dp[pos]=0;
        return 0;
    }
    int wordBreak(string A, vector<string> &B) {
        unordered_set<string>st;
        memset(dp, -1, sizeof(dp));
        
        for(int i=0; i<B.size(); i++){
            st.insert(B[i]);
        }
        
        return wordFind(A, 0, st);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends