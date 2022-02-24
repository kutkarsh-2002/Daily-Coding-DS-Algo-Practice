class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=INT_MIN;
        int j=-1;
        for(int i=0; i<nums.size(); i++){
            if(mx<nums[i]){
                mx=nums[i];
                j=i;
            }
        }
       
        int smx=INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            if(smx<nums[i] && i!=j){
                smx=nums[i];
            }
        }
       
        return ((mx-1)*(smx-1));
    }
};