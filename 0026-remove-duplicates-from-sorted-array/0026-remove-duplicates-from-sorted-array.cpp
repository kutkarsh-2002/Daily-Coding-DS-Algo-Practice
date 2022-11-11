class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        
        
//         for(int i=0; i<n-1; i++){
//             for(int j=i+1; j<n; j++){
//                 if(nums[i]==nums[j]){
//                     for(int k=j; k<n; k++){
//                         nums[k]=nums[k+1];
                        
//                     }
//                     j--;
//                     n--;
//                 }
                 
//             }
//         }
//         return n;
        
        
        int i;
        int temp=nums[0];
        int targetindex=1;
        for(i=1; i<n; i++){
            if(nums[i]!=temp){
                temp=nums[i];
                nums[targetindex]=nums[i];
                targetindex++;
            }
        }
        
        return targetindex;
        
    
        
    }
};