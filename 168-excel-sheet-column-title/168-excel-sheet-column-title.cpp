class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        if(columnNumber>=1 && columnNumber<=26){
            res=res+(char)('A'+(columnNumber-1));
            return res;
        }
        
        while(columnNumber>0){
            columnNumber--;
            res=(char)('A'+(columnNumber%26))+res;
            columnNumber/=26;
            
        }
        
        return res;
    }
};