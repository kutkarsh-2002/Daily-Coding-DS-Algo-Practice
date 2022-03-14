class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        
        if(k%2!=0 && (nums.size()==1 || nums.size()==0))
           return -1;
        
        if(k>nums.size()){
            return *max_element(nums.begin(), nums.end());
        }
        
        int val=INT_MIN;
        int count=k;
        
        for(int i=0; i<nums.size() && k>1; i++){
            if(val<nums[i]){
                val=nums[i];
            }
            k--;
        }
        
        if(nums[count]>val){
            return nums[count];
        }
        return (val!=INT_MAX)?val:-1; 
           
    }
};