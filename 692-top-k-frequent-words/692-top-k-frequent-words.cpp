class Solution {
public:
    static bool cmp(pair<string, int>&x, pair<string, int>&y){
        if(x.second>y.second) return true;
        else if(x.second<y.second) return false;
        else if(x.second==y.second){
            string a=x.first, b=y.first;
            
            if (a.compare(0, b.size(), b) == 0 || b.compare(0, a.size(), a) == 0)
                return a.size() < b.size();
 
            else
                return a < b;
        }
        
        return false;
    }
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string, int>mp;
        
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        vector<pair<string, int>>v;
        
        for(auto x:mp){
            v.push_back({x.first, x.second});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        for(int i=0; i<k; i++){
            ans.push_back(v[i].first);
        }
        
        return ans;
    }
};