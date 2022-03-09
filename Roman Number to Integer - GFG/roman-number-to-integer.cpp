// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
  int find(char ch){
      if(ch=='I')
      return 1;
      else if(ch=='V')
      return 5;
      else if(ch=='X')
      return 10;
      else if(ch=='L')
      return 50;
      else if(ch=='C')
      return 100;
      else if(ch=='D')
      return 500;
      else
      return 1000;
      
  }
    int romanToDecimal(string &str) {
        int res=0;
        if(str.size()==0)
        return 0;
        
        if(str.size()==1){
            return find(str[0]);
        }
        
        for(int i=0; i<str.size(); i++){
            
            if(i<str.size()-1 && find(str[i])<find(str[i+1])){
                res+=(find(str[i+1])-find(str[i]));
                i++;
            }else{
                //cout<<find(str[i])<<endl;
                res+=find(str[i]);
            }
        }
        
        return res;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends