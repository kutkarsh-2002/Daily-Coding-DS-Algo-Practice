class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int>mp;
        int j=0, i=0;
        long long sum=0, mxSum=INT_MIN;
        
        
        for(i=0; i<nums.size() && j<nums.size(); )
        {   
            if(mp.empty()){
                mp.insert({nums[j], 1});
                sum+=nums[j];
                j++;
            }
            else if(mp.find(nums[j])==mp.end())
            {   mp.insert({nums[j], 1});
                sum+=nums[j];
                j++;
            }
            else if(mp.find(nums[j])!=mp.end())
            {
                mxSum=max(mxSum, sum);
                while(nums[i]!=nums[j])
                {
                    mp.erase(nums[i]);
                    sum-=nums[i];
                    i++;
                }
                
                i++;
                j++;
            }
            
        }
        
        mxSum=max(mxSum, sum);
        
        return mxSum;
        
        
    }
};