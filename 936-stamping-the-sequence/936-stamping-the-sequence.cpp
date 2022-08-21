class Solution {
public:

    bool CheckAndReplace(string &target, int &start, string &stamp, int &stars, vector<int>&ans){
       int m=stamp.size();
        
        for(int i=0; i<m; i++){
            if(target[i+start]!='?' && target[i+start]!=stamp[i]) return false;
        }
        
        ans.push_back(start);
        
        for(int i=start; i-start<m; i++){
            stars+=(target[i]!='?'), target[i]='?';
        }
        return true;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        vector<int>ans;
        int stars=0, n=target.size(), m=stamp.size();
        
        vector<bool>vis(n, false);
        
        while(stars<n){
            bool replaced = false;
            for(int i=0; i<=n-m && stars<n; i++){
                if(!vis[i]){
                    replaced=CheckAndReplace(target, i, stamp, stars, ans);
                    vis[i]=replaced;
                }
            }
            
            if(!replaced) return {};
        }
        
        reverse(begin(ans), end(ans));
        
        return ans;
        
    }
};