class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int, int>mp;
        int res=0;
        
        for(int i:nums){
            mp[i]++;
        }
        
        for(auto x:mp){
            
            if(k==0)
            {
                if(x.second>1)
                    res++;
            }
            else if(mp.find(x.first+k)!=mp.end())
                res++;
        
        }
        
        return res;
    }
};