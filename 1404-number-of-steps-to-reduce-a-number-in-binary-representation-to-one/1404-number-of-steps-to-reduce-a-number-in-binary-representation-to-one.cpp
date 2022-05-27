class Solution {
public:
    int numSteps(string s) {
        int j, count;
        count = 0;
        
        // j pointer starts from the end of the string.
        j=s.length()-1;
        
        while(j>0){
            // divide by 2 action.
            if(s[j]=='0'){
                j--;
                count++;
            }
            else{
                // add 1 action.
                count++;
                // each 1 converted to 0 is then divided by 2.
                while(j>=0 and s[j]=='1'){
                    j--;
                    count++;
                }
                // if not the end of string then convert the s[j] = 0 to 1.
                if(j>0)
                    s[j]='1';
            }
        }
        
        return count;
    }
};