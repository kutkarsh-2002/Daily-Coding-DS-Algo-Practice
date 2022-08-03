class Solution {
public:
    
    void subSet(int i, vector<int>&v, vector<int>&nums, vector<vector<int>>&res){
        
            
       res.push_back(v);
                
       for(int j=i; j<nums.size(); j++){
            
            if(j!=i && nums[j]==nums[j-1]) continue;

                v.push_back(nums[j]);
                subSet(j+1, v, nums, res);
                v.pop_back();   

            }
        
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>v;
        sort(nums.begin(), nums.end());
        
        subSet(0, v, nums, res);
        
        
        return res;
    }
};