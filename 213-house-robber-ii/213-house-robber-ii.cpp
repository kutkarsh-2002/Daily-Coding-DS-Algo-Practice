class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n==0)
            return 0;
        
        if(n==1)
            return nums[0];
        
        if(n==2)
            return max(nums[0], nums[1]);
        
        if(n==3)
            return max(nums[0], max(nums[1], nums[2]));
        
        int dp1[n], dp2[n];
        
        //dp1 => from 1 to n-1 house
        //dp2 => from 2 to n house 
        // in order to avoid adjacent in circular array condition
        
        dp1[0]=nums[0];
        dp1[1]=nums[0];
        
        dp2[0]=0;
        dp2[1]=nums[1];
        
        for(int i=2; i<n; i++){
            dp1[i]=max(dp1[i-2]+nums[i], dp1[i-1]);
            dp2[i]=max(dp2[i-2]+nums[i], dp2[i-1]);
        }
        
        return max(dp1[n-2], dp2[n-1]);
        
        
        
    }
};