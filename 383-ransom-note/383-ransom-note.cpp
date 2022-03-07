class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int>v(256, 0);
        for(int i=0; i<magazine.size(); i++){
            v[magazine[i]]++;
        }
        
        for(int i=0; i<ransomNote.size(); i++){
            if(--v[ransomNote[i]]<0){
                return false;
            }
            
        }
        
        return true;
    }
};