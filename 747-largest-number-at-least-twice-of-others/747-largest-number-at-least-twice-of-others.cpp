class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        /*unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            mp.insert({nums[i], i});
        }
        
        sort(nums.begin(), nums.end());
        
        int mx=nums[nums.size()-1];
        
        for(auto x: mp){
            if(mx!=x.first && mx<2*x.first)
                return -1;
        }
        
        return mp[mx];*/
        
        int mx=nums[0];
        int index=0;
    
        for(int i=1; i<nums.size(); i++){
            if(mx<nums[i])
            {
                mx=nums[i];
                index=i;
            }
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[index]<2*nums[i] && index!=i)
                return -1;
        }
        
        return index;
    }
};