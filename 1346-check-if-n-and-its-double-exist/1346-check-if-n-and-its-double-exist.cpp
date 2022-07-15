class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        
        unordered_map<int, int>mp;
        
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        
        if(mp.find(0)!=mp.end() && mp[0]>1)
            return true;
        
        for(int i=0; i<arr.size(); i++){
            if(mp.find(arr[i]*2)!=mp.end() && arr[i]*2!=0)
                return true;
        }
        
        return false;
    }
};