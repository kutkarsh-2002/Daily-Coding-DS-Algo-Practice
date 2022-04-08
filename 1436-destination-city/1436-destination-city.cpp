class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string>mp;
        
        for(int i=0; i<paths.size(); i++){
            if(mp.find(paths[i][0])==mp.end() || mp[paths[i][0]]==""){
                mp[paths[i][0]]=paths[i][1];
                if(mp.find(paths[i][1])==mp.end()){
                    mp[paths[i][1]]="";
                }
            }
        }
        
        for(auto x:mp){
            if(x.second==""){
                return x.first;
            }
        }
        
        return "-1";
    }
};