class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans= INT_MIN;
        int maxval=1;
        int minval=1;
        int prevMax;
        
        for(int i=0; i<nums.size(); i++){
            
            if(nums[i]>0){
                maxval=maxval*nums[i];
                minval=min(1, minval*nums[i]);
            }
            else if(nums[i]==0){
                maxval=0;
                minval=1;
            }
            else if(nums[i]<0){
                prevMax=maxval;
                maxval=minval*nums[i];
                minval=prevMax*nums[i];
            }
            
            ans=max(ans, maxval);
            
            if(maxval<=0){
                maxval=1;
            }
        }
        return ans;
        
    }
};