class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int i=0, j=0;
        int res=INT_MAX;
        
        while(i<nums.size() && j<nums.size())
        {
            if((j-i)+1==k){
                res=min(res, (nums[j]-nums[i]));
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        
        return res;
    }
};