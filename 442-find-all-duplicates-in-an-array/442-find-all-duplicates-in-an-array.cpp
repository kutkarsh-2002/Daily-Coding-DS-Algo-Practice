class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        unordered_map<int, int>mp;
        vector<int>v;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        for(auto x: mp){
            if(x.second>1)
                v.push_back(x.first);
        }
        
        return v;
    }
};