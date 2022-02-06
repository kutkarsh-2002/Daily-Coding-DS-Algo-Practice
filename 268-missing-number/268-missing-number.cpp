class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            
            if(nums[i]!=i)
            {
                ans=i;
                break;
            }
        }
        if(nums[nums.size()-1]!=nums.size())
            return nums.size();
        return ans;
    }
};