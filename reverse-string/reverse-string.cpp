class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int last=s.size()-1;
        int first=0;
        while(last>first){
            swap(s[last], s[first]);
            first++;
            last--;
        }
        
        
    }
};