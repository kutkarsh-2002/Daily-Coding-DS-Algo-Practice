class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        if(text=="balon" || text=="ballon" || text=="baloon")
            return 0;
        
        unordered_map<char, int>mp;
        
        for(int i=0; i<text.size(); i++){
            
            if(text[i]=='b' || text[i]=='a' || text[i]=='l' || text[i]=='o' || text[i]=='n')
                mp[text[i]]++;
        }
        
        if(mp.size()!=5)
            return 0;
        
        int res;
        
       res=min(mp['b'],min(mp['a'],min(mp['l']/2,min(mp['o']/2,mp['n']))));
        return res;
    }
}; 