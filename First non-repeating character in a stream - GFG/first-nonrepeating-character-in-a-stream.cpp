// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    
		  //Finding first non-repeating character
		    
		  //  char s=' ';
		  //  int temp[256];
		    
		  //  fill(temp, temp+256, 0);
		  //  string ans="";
		   
		  //  for(int i=0; i<A.size(); i++){
		  //      if(temp[A[i]]==0 && s==' '){
		  //          ans+=A[i];
		  //          temp[A[i]]++;
		  //          s=A[i];
		            
		  //      }else if(temp[A[i]]>0 && s==A[i]){
		  //          ans+='#';
		  //          temp[A[i]]++;
		  //          s=' ';
		  //      }else if(temp[A[i]]==0 && s!=' '){
		  //          ans+=s;
		            
		  //      }
		        
		  //  }
		    
		  //  return ans;
		  
		   /*
		   //using hastable to check the repeation of character
		    unordered_set<char, int>s;
		    s.insert(A[0]);
		    //using temp as empty string toreturn the result.
		    string temp="";
		    temp+=A[0];
		    for(int i=1; i<A.size(); i++){
		        
		        if(s.find(A[i])==s.end()){
		            temp+='#';       //if character of string is already repeating
		        }else if(s.find(A[i])!=s.end() && i<j){
		            temp+=A[i];          // if character of string is non-repeating and its index value is less than the index value of first non-repeating character.
		            s.insert(A[i]);
		        }else if(s.find(A[i])!=s.end() && j>=0){
		            temp+=A[j];          // if character of string is non-repeating but its index value is greater than the first non-repeating character.
		            s.insert(A[i]);
		        }else{
		            temp+=A[i];         // handling case if j<0
		            s.insert(A[i]);
		        }
		    }
		    
		    return temp;
		    */
		    
		    vector<int>cnt(26, -1);
		    string ans = "";
		    for(int i=0;i<A.size();i++) {
		        if(cnt[A[i] - 'a'] == -1) {
		            cnt[A[i] - 'a'] = i;
		        }
		        else {
		            cnt[A[i] - 'a'] = -2;
		        }
		     
		        char c = '#';
		        int mn = INT_MAX;
		        for(int j=0;j<26;j++) {
		            if(cnt[j] >= 0 && cnt[j] < mn) {
		                mn = cnt[j];
		                c = (j + 'a');
		            }
		        }
		    
		        ans += c;
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends