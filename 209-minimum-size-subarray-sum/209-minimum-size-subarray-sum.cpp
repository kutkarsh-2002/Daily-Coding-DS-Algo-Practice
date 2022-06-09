class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i=0, j=0, n=nums.size();
        int sum=0, res=INT_MAX;
        
        while(i<n && j<n){
            sum+=nums[j];
            if(sum>=target){
                res=min(res, (j-i)+1);
                sum=0;
                i++;
                j=i;
            }
            else{
                
                j++;
                
            }
        }
        
        if(sum>=target){
            res=min(res, (j-i)+1);
        }
        return (res!=INT_MAX)?res:0;
    }
};