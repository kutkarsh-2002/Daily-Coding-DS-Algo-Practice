class Solution {
public:
    /*bool check(vector<int>&nums, int st){
        if(st==nums.size()-1)
            return true;
        else if(nums[st]==0 && st<nums.size()-1){
            return false;
        }
        
        for(int i=0; i<nums[st] && st<nums.size();){
            check(nums, i+1);
            //check(nums, i-1);
        }
        
        return false;
    }*/
    //Capture the maximum projectile distance it has reached
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        int reachable=0;
        
        for(int i=0; i<nums.size(); i++){
            
            if(reachable<i)
                //we cant jump from that index
                return false;
            
            reachable=max(reachable, i+nums[i]);
        }
        
        return true;
    }
};