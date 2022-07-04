class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        
        string x=s, y=s;
        unordered_map<char, char>mp;
        unordered_map<char, char>mpt;
        
        
        
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
        
        
        for(int i=0; i<s.size(); i++){
            if(mpt.find(s[i])!=mpt.end() && mpt[s[i]]!=t[i]){
                return false;
            }
            else if((mpt.find(s[i])!=mpt.end() && mpt[s[i]]==t[i])){
                string temp="";
                temp+=t[i];
                x.replace(i, 1, temp);
                //cout<<x<<endl;
                
            }
            else if(mpt.empty() || mpt.find(s[i])==mpt.end()){
                string temp="";
                temp+=t[i];
                mpt.insert({s[i], t[i]});
                x.replace(i, 1, temp);
                //cout<<x<<endl;
                
                
            }
        }
        
        
        if(x!=t) return false;
        
        return true;
        
        
        
    }
};