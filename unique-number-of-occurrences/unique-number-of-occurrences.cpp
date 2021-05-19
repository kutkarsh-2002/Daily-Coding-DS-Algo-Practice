class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>a;
        
        unordered_map<int, int>mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
            
        }
        for(auto x:mp){
            
            a.push_back(x.second);
        }
        
        
        unordered_set<int> s;
        
        for (int i = 0; i <a.size(); i++) {
            s.insert(a[i]);
        }

        if (s.size() == a.size()){
            return true;
        }
        
        return false;
        
    }
};