// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	    void permutation(string s, int i, vector<string>&res){
	        if(i>=s.size()){
	            res.push_back(s);
	            return;
	        }
	        
	        for(int j=i; j<s.size(); j++){
	            swap(s[i], s[j]);
	            permutation(s, i+1, res);
	            swap(s[i], s[j]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string>res;
		    permutation(S, 0, res);
		    sort(res.begin(), res.end());
		    return res;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends