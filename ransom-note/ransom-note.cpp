class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        /*
        int n=magazine.size(), m=ransomNote.size();
        
        for(int i=0; i<=n-m;){
            int j;
            for(int j=0; j<m; j++){
                if(ransomNote[j]!=magazine[i+j]){
                    break;
                }
            }
            
            if(j==m){
                return true;
            }
            else if(j==0){
                i++;
            }else{
                i=i+j;
            }
        }
        
        return false;*/
        
        //return (magazine.find(ransomNote)!=string::npos);
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