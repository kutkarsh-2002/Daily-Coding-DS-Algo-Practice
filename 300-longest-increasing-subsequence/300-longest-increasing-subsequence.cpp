class Solution {
public:
//     int LIS(int i, int prev, int n, vector<int>& nums, vector<vector<int>>&dp){
//         if(i==n) return 0;
        
//         if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        
//         int take=0;
//         if(prev==-1 || nums[prev]<nums[i]){
//             take=1+LIS(i+1, i, n, nums, dp);
//         }
        
//         int nottake=LIS(i+1, prev, n, nums, dp);
        
//         return dp[i][prev+1]=max(take, nottake);
//     }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
//         vector<vector<int>>dp(n, vector<int>(n+1, -1));
        
//         return LIS(0, -1, n, nums, dp);
        
        /* Tabulation */
        
       
//         vector<int>dp(n, 1);
        
//         for(int i=0; i<n; i++){
//             for(int prev=0; prev<i; prev++){
                
//                 if(nums[i]>nums[prev]){
//                     dp[i]=max(dp[i], 1+dp[prev]);
//                 }
//             }
//         }
        
//         return *max_element(dp.begin(), dp.end());
        
    /* Printing LIS */
        
//         vector<int>dp(n, 1), hash(n);
//         int maxi=1;
//         int lastInd=0;
        
//         for(int i=0; i<n; i++){
//             hash[i]=i;
//             for(int prev=0; prev<i; prev++){
                
//                 if(nums[i]>nums[prev] && dp[i]<1+dp[prev]){
//                     dp[i]=1+dp[prev];
//                     hash[i]=prev;
//                 }
//             }
//             if(dp[i]>maxi){
//                 maxi=dp[i];
//                 lastInd=i; 
//             }
//         }
//         vector<int>temp;
        
//         while(hash[lastInd]!=lastInd){
//             temp.push_back(nums[lastInd]);
//             lastInd=hash[lastInd];
//         }
//         temp.push_back(nums[lastInd]);
//         reverse(temp.begin(), temp.end());
        
//         for(auto x: temp){
//             cout<<x<<" ";
//         }
        
//         return maxi;
        
        /* Binary Search */
        
        vector<int>temp;
        temp.push_back(nums[0]);
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                
                int ind=lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        
        return temp.size();
    }
};