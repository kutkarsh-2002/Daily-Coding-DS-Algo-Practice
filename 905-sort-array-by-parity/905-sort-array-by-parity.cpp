class Solution {
public:
//     int parityCount(int n){
//         int res=0;
//         while(n>0){
//             n=n&(n-1);
//             res++;
//         }
        
//         return res;
//     }
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>res;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0){
                res.push_back(nums[i]);
            }
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2!=0){
                res.push_back(nums[i]);
            }
        }
        
        return res;
    }
};