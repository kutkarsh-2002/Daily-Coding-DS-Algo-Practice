class Solution {
public:
    int countSubsets(vector<int>&nums, int s){
        int n=nums.size();
        int t[n+1][s+1];
        
        for(int i=0; i<=n; i++){
            
            t[i][0]=1;
        }
        
        for(int j=1; j<=s; j++){
            t[0][j]=0;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=s; j++){
                
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j]+t[i-1][j-nums[i-1]];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        
        return t[n][s];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        
        int s2=(sum-target)/2;
        
        if((sum-target)%2==1 || target>sum)
            return 0;
        
        return countSubsets(nums, s2);
    }
};