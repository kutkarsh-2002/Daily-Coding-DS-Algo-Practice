class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        
        unordered_map<char, char>mp;
               
        
        for(int i=0; i<s.size(); i++){
            if(mp.find(t[i])!=mp.end() && mp[t[i]]!=s[i]){
                return false;
            }
            else if(mp.empty() || mp.find(t[i])==mp.end()){
                
                mp.insert({t[i], s[i]});
                
                
                
            }
        }
        
        
        mp.clear();
        
        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]]!=t[i]){
                return false;
            }
            else if(mp.empty() || mp.find(s[i])==mp.end()){
                
                mp.insert({s[i], t[i]});
                  
            }
        }
        
        
        return true;
        
        
        
    }
};