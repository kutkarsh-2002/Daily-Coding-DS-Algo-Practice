/*class Solution {
public:
    bool isPalindrome(string &temp){
        if(temp.size()==0 || temp.size()==1)
            return true;
        
        int i=0, j=temp.size()-1;
        
        while(i<j){
            if(temp[i]!=temp[j]){
                return false;
            }
            else{
                
                i++;
                j--;
            }
        }
        
        return true;
    }
    
    void substring(string &s, int start, int end, long long &count){
        if(end==s.size())
            return ;
        
        else if(start>end){
            
            substring(s, 0, end+1, count);
        }
        else{
            string temp="";
            for(int i=start; i<end; i++){
                temp+=s[i];
            }
            
            temp+=s[end];
            
            //cout<<temp<<endl;
            
            if(isPalindrome(temp)){
                count++;
            }
            
            substring(s, start+1, end, count);
        }
        
        return ;
    }
    
    int countSubstrings(string s) {
        long long count=0;
        substring(s, 0, 0, count);
        
        return count;
    }
};*/

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++) {
            int k = i + 1;
            int j = i - 1;
            while(j >= 0 && k < n && s[k] == s[j])ans++, j--, k++;
            
            k = i + 1;
            j = i;
            while(j >= 0 && k < n && s[k] == s[j])ans++, j--, k++;
            ans++;
        }
        return ans;
    }
};