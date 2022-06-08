class Solution {
public:
    bool isPal(string &s){
        string temp=s;
        
        reverse(s.begin(), s.end());
        
        return (s==temp);
    }
    int removePalindromeSub(string s) {
        if(s=="") return 0;
        
        return (isPal(s))?1:2;
    }
};