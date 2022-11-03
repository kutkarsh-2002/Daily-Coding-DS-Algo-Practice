class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string, int>mp;
        
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        
       
        int res=0, mid=0;
        
        for(auto [s, f]:mp){
            
            string temp=s;
            reverse(temp.begin(), temp.end());
            
            if(s!=temp){
                
                if(mp.count(temp)){
                    res+=min(mp[temp], mp[s]);
                }
            }
            else{
                res+=f;
                
                if(f&1){
                    mid=1;
                    res-=1;
                }
            }
              
        }
        
        res+=mid;
        
        return res*2;
    }
};