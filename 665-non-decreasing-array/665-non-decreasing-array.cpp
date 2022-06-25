class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1 || nums.size()==2) return true;
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                if((i-1)>=0 && nums[i-1]>nums[i+1]){
                    nums[i+1]=nums[i];
                }
                else{
                    nums[i]=nums[i+1];
                }
                
                break;
            }
        }
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                return false;
            }
        }
        
        return true;
    }
};