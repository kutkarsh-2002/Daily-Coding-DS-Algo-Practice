class Solution {
public:
    void findingPermut(vector<int>&nums, vector<vector<int>>&res, int i){
        
        if(i>=nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int j=i; j<nums.size(); j++){
            swap(nums[i], nums[j]);
            findingPermut(nums, res, i+1);
            swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>res;
        findingPermut(nums, res, 0);
        return res;
    }
};