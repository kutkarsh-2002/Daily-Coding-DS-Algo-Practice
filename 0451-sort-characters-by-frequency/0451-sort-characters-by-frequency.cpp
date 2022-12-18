class Solution {
public:
    
   static bool sortbyF(pair<char, int>&a, pair<char, int>&b){
        return a.second>b.second;
    }
    
    string frequencySort(string s) {
        
        unordered_map<char, int>mp;
        
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        
        vector<pair<char, int>>v;
        
        for(auto x: mp){
            v.push_back({x.first, x.second});
        }
        
        sort(v.begin(), v.end(), sortbyF);
        
        string res="";
        
        
        for(int i=0; i<v.size(); i++){
            int f=v[i].second;
            
            while(f--){
                res+=v[i].first;
            }
        }
        
        
        return res;
        
    }
};