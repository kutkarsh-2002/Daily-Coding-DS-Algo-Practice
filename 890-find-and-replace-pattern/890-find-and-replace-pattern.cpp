class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>v;
        unordered_map<char, int>mp;
        
        for(int i=0; i<pattern.size(); i++){
            mp[pattern[i]]++;
        }
        
        for(int i=0; i<words.size(); i++){
            string s=words[i];
    
            if(s.size()!=pattern.size()) continue;
            
            unordered_map<char, int>ms;
            
            for(int i=0; i<s.size(); i++){
                ms[s[i]]++;
            }
            
            
            bool flag=false;
            if(mp[pattern[0]]!=ms[s[0]]) flag=false;
            
            for(int i=1; i<pattern.size(); i++){
                
                if(mp[pattern[i]]!=ms[s[i]]){
                    flag=true;
                    break;
                }
                else if(pattern[i]!=pattern[i-1] && s[i]==s[i-1]){
                    flag=true;
                    break;
                }
                else if(pattern[i]==pattern[i-1] && s[i]!=s[i-1]){
                    flag=true;
                    break;
                }
            }
            
            if(flag==false){
                v.push_back(words[i]);
            }
        }
        
        return v;
    }
};