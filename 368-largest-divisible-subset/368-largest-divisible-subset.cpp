class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        vector<int>ans;
        vector<int>dp(n, 1), hash(n);
        int maxi=1, lastInd=0;
        
        for(int i=0; i<n; i++){
            hash[i]=i;
            for(int prev=0; prev<i; prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            
            if(maxi<dp[i]){
                maxi=dp[i];
                lastInd=i;
            }
            
        }
        
        while(hash[lastInd]!=lastInd){
            ans.push_back(nums[lastInd]);
            lastInd=hash[lastInd];
        }
        
        ans.push_back(nums[lastInd]);
        cout<<maxi<<endl;
        return ans;
    }
};