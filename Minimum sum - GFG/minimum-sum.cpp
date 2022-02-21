// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        
        if(n==1){
            return to_string(arr[0]);
        }
        sort(arr, arr+n);
        string s1="", s2="";
        
        for(int i=0;i<n;i++){
            if(i%2==0)
              s1+=to_string(arr[i]);
            else
              s2+=to_string(arr[i]);
        }
        
        string sum="";
        int c=0;
        int i=s1.size()-1;
        int j=s2.size()-1;
        
        while(i>=0 && j>=0){
            int x=s1[i]-'0';
            int y=s2[j]-'0';
            int l=(x+y+c)%10;
            c=(x+y+c)/10;
            sum+=to_string(l);
            i--;
            j--;
        }
        
        while(i>=0){
            int x=s1[i]-'0';
            
            int l=(x+c)%10;
            c=(x+c)/10;
            sum+=to_string(l);
            i--;
            
        }
        
        while(j>=0){
            int y=s2[j]-'0';
            
            int l=(y+c)%10;
            c=(y+c)/10;
            sum+=to_string(l);
            j--;
            
        }
        if(c!=0){
             sum+=to_string(c);
         }
         string res="";
         int h=sum.size()-1;
         
         while(h>=0 && sum[h]=='0')
            h--;
        
        for(; h>=0; h--){
            res+=sum[h];
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends