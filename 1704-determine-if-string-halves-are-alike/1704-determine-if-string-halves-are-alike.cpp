class Solution {
public:
    bool halvesAreAlike(string s) {
        
        if(s.size()==0) return true;
        
        if(s.size()==2){
            return ((tolower(s[0])=='a' || tolower(s[0])=='e' || tolower(s[0])=='i' || tolower(s[0])=='o' || tolower(s[0])=='u') && (tolower(s[1])=='a' || tolower(s[1])=='e' || tolower(s[1])=='i' || tolower(s[1])=='o' || tolower(s[1])=='u'));
        }
        
        int fh=0;
        
        for(int i=0; i<s.size()/2; i++){
            if(tolower(s[i])=='a' || tolower(s[i])=='e' || tolower(s[i])=='i' || tolower(s[i])=='o' || tolower(s[i])=='u'){
                fh++;
            }
        }
        
        int sh=0;
        for(int i=s.size()/2; i<s.size(); i++){
            if(tolower(s[i])=='a' || tolower(s[i])=='e' || tolower(s[i])=='i' || tolower(s[i])=='o' || tolower(s[i])=='u'){
                sh++;
            }
        }
        
        return (fh==sh);
    }
};