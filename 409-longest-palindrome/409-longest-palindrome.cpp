class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int>mp;
        int c=0;
        for(int i=0; i<s.size();i++){
            mp[s[i]]++;
        }
        
        for(auto x: mp){
            if(x.second%2!=0){
                c++;
            }
        }
        
        if(c>1){
          return  s.size()-c+1;
        }
        
        return s.size();
    }
};