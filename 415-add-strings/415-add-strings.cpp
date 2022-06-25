class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans="";
        
        int n=min(num1.size(), num2.size());
        int c=0;
        int i;
        for(i=0; i<n; i++){
            int val=num1[i]-'0'+num2[i]-'0'+c;
            
            if(val>9){
                c=val/10;
                val=val%10;
            }else{
                c=0;
            }
            
            ans+=to_string(val);
        }
        
        while(i<num1.size()){
            int val=num1[i]-'0'+c;
            
            if(val>9){
                c=val/10;
                val=val%10;
            }else{
                c=0;
            }
            
            ans+=to_string(val);
            i++;
        }
        
        while(i<num2.size()){
            int val=num2[i]-'0'+c;
            
            if(val>9){
                c=val/10;
                val=val%10;
            }else{
                c=0;
            }
            
            ans+=to_string(val);
            i++;
        }
        
        if(c>0){
            ans+=to_string(c);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};