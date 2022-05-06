class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
    
        unordered_map<string, int>mp;
        
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        
        
        string temp="";
        int ans=0;
        
        for(int i=0; i<s.size(); i++){
            temp+=s[i];
            
            if(mp.find(temp)!=mp.end()){
                ans+=mp[temp];
            }
            
        }
        
        return ans;
    }
};