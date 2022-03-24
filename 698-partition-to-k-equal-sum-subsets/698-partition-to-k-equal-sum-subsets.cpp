class Solution {
public:
    
    /*bool backtrack(vector<int>& nums,vector<int>visited, int target, int curr_sum, int i, int k) {
		if (k == 1) return true;

		if (curr_sum == target) return backtrack(nums, visited, target, 0, 0, k-1);

		for (int j = i; j < nums.size(); j++) {
			if (visited[j] || curr_sum + nums[j] > target) continue;

			visited[j] = true;
			if (backtrack(nums, visited, target, curr_sum + nums[j], j+1, k)) return true;
			visited[j] = false;
		}

		return false;
	}*/
    
    int dp[(1<<16)+2];
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        /*int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }  
        
        if(nums.size()<k || sum%k){
            return false;
        }
        if(k==1){
            return true;
        }
        
        vector<int>visited(nums.size(), false);
        
        return backtrack(nums, visited, sum / k, 0, 0, k);*/
        
        int n = nums.size(), sum = 0;
        fill(dp, dp+(1<<16)+2, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % k) return false;
        int tar = sum/k;
        
        for (int mask = 0; mask < (1<<n); mask++) {
            if (dp[mask] == -1) continue;  // if current state is illegal, simply ignore it
            for (int i = 0; i < n; i++) {
                if (!(mask&(1<<i)) && dp[mask]+nums[i] <= tar) {  // if nums[i] is unchosen && choose nums[i] would not cross the target
                    dp[mask|(1<<i)] = (dp[mask]+nums[i]) % tar;
                }
            }
        }
        return dp[(1<<n)-1] == 0;
        
        
    }
    
    
};