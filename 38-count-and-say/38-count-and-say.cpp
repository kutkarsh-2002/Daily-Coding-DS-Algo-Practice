class Solution {
public:
    
    string find(int n){
        if(n==1){
            return "1";
        }
        
       string temp=find(n-1);
        //cout<<temp<<" ";
        int j=1;
        string ans="";
        
        if(temp.size()==1){
            ans+=to_string(j)+temp[0];
            return ans;
        }
        
        for(int i=1; i<temp.size(); i++){
            if(temp[i]==temp[i-1]){
                j++;
            }
            else{
                ans+=to_string(j)+temp[i-1];
                j=1;
            }
        }
          
        ans+=to_string(j)+temp[temp.size()-1];
        
        
        
        return ans;
    }
    
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
         return find(n);
         
    }
};