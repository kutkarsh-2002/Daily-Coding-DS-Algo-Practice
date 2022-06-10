class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") return 0;
        if(s.size()==1) return 1;
        
        unordered_map<char, int>mp;
        mp.insert({s[0], 1});
        int j=1, i=0, res=0;
        
        for(i=0; i<s.size() && j<s.size(); ){
            
           if(mp.find(s[j])==mp.end())
           {
               mp.insert({s[j], 1});
               j++;
           }
            else if(mp.find(s[j])!=mp.end())
            {   res=max(res, (j-i));
             
                while(s[i]!=s[j]){
                    mp.erase(s[i]);
                    i++;
                }
             
                i++;
                j++;
                
            }
            
        }
        res=max(res, (j-i));
        
        return res;
    }
};