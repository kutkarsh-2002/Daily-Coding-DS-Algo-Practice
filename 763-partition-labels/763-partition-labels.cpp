class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int>mp;
        vector<int>res;
        
        for(int i=0; i<s.size(); i++){
            mp[s[i]]=i;
        }
        
        int range=0, i=0;
        
        while(i<s.size()){
            range=mp[s[i]];
            for(int j=i; j<=range; j++){
                range=max(range, mp[s[j]]);
            }
            res.push_back((range+1)-i);
            i=range+1;
            
        }
        
        return res;
    }
};