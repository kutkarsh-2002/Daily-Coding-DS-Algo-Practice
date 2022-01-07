class Solution {
public:
    char findTheDifference(string s, string t) {
        
        unordered_map<char, int>mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        
        for(int i=0; i<t.size(); i++){
            mp[t[i]]--;
        }
        for(auto x:mp){
            if(x.second!=0){
                return x.first;
            }
        }
        return '-1';
    }
};