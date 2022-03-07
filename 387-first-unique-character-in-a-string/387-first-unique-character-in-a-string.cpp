class Solution {
public:
    int firstUniqChar(string s) {
        
        if(s.empty())
            return -1;
        vector<int>v(256, 0);
        
        for(int i=0; i<s.size(); i++){
            v[s[i]]++;
        }
        
        for(int i=0; i<s.size(); i++){
            if(v[s[i]]==1){
                return i;
            }
        }
        
        return -1;
    }
};