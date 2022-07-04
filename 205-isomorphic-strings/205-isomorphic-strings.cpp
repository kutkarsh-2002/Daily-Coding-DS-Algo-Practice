class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        
        string x=s, y=s;
        unordered_map<char, char>mp;
        //unordered_map<char, char>mpt;
        
        
        
        for(int i=0; i<s.size(); i++){
            if(mp.find(t[i])!=mp.end() && mp[t[i]]!=s[i]){
                return false;
            }
            else if((mp.find(t[i])!=mp.end() && mp[t[i]]==s[i])){
                string temp="";
                temp+=t[i];
                y.replace(i, 1, temp);
                
            }
            else if(mp.empty() || mp.find(t[i])==mp.end()){
                string temp="";
                temp+=t[i];
                mp.insert({t[i], s[i]});
                y.replace(i, 1, temp);
                
                
            }
        }
        
        if(y!=t) return false;
        mp.clear();
        
        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]]!=t[i]){
                return false;
            }
            else if((mp.find(s[i])!=mp.end() && mp[s[i]]==t[i])){
                string temp="";
                temp+=t[i];
                x.replace(i, 1, temp);
                //cout<<x<<endl;
                
            }
            else if(mp.empty() || mp.find(s[i])==mp.end()){
                string temp="";
                temp+=t[i];
                mp.insert({s[i], t[i]});
                x.replace(i, 1, temp);
                //cout<<x<<endl;
                
                
            }
        }
        
        
        if(x!=t) return false;
        
        return true;
        
        
        
    }
};