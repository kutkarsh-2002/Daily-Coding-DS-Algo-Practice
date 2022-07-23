class Solution {
public:
    
    
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int>ans(nums.size(), 0);
        
        for(int i=0; i<nums.size(); i++){
            int count=0;
            for(int j=0; j<nums.size(); j++){
                if(i!=j && (nums[i]>nums[j])){
                    count++;
                }
            }
            ans[i]=count;
        }
        
        return ans;
    }
};