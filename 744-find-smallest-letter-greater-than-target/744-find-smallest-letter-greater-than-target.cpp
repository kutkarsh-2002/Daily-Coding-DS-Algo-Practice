class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i=0, j=letters.size()-1;
        
        char ans=' ';
        
        while(i<=j){
            int mid=(i+j)/2;
            
            if(letters[mid]-'0'>target-'0'){
                ans=letters[mid];
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        
        return (ans==' ')?letters[0]:ans;
    }
};