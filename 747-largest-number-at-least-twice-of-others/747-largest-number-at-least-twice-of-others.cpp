class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            mp.insert({nums[i], i});
        }
        
        sort(nums.begin(), nums.end());
        
        int mx=nums[nums.size()-1];
        
        for(auto x: mp){
            if(mx!=x.first && mx<2*x.first)
                return -1;
        }
        
        return mp[mx];
    }
};