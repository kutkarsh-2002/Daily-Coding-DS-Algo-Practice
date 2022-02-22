class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        if(columnTitle.size()==1){
            return (1+(columnTitle[0]-'A'));
        }
        
        int result=0;
        int n=columnTitle.size();
        
        int i=0;
        while(n--){
            int d=1+(columnTitle[i]-'A');
            result=result*26+d;
            i++;
        }
                     
        return result;
        
    }
};