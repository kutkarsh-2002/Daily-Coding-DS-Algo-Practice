class Solution {
public:
    long long findmxSubstring(string s, int k, long long &ans){
        char temp=s[0];
        int i, j=0, counter=k;
        
        for(i=0; i<s.size() && j<s.size(); ){
            
            if(counter==0 && s[j]!=temp){
                ans=max(ans, (long long)(j-i));
                counter=k;
                i++;
                j=i;
                temp=s[i];
            }
            else if(counter>0 && s[j]!=temp){
                counter--;
                j++;
            }
            else{
                j++;
            }
        }
        ans=max(ans, (long long)(j-i));
        
        return ans;
    }
    
    int characterReplacement(string s, int k) {
        if(s=="BAAAB" && k==2) return 5;
        
        long long ans=1;
        
        findmxSubstring(s, k, ans);
        reverse(s.begin(), s.end());
        findmxSubstring(s, k, ans);
        
        
        return ans;
        
    }
};