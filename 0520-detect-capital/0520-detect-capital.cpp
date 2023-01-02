class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()==0 || word.size()==1){
            return true;
        }
        int i=1;
        while(i<word.size()){
            
            if((islower(word[i]) && islower(word[i-1])) || (isupper(word[i]) && isupper(word[i-1])) || (isupper(word[0]) && i==1)){
                i++;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};