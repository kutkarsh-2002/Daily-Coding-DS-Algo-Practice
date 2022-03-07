class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
    int Tsum=0;
    for(int i=0; i<nums.size(); i++){
        Tsum+=nums[i];
    }
    
    int prevSum=0;
        
    for(int i=0; i<nums.size(); i++){
        if(prevSum==(Tsum-(prevSum+nums[i]))){
            return i;
            
        }
        else{
            prevSum+=nums[i];
        }
    }
    
        return -1;
        
    }
};