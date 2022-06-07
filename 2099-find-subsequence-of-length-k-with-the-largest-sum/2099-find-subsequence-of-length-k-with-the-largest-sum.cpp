class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>ans(k);
        
        int t=k, i=0;
        while(t--){
            ans[i]=nums[i];
            i++;
        }
        
        for(int j=i; j<nums.size(); j++){
            int mini = min_element(ans.begin(), ans.end()) - ans.begin();
            //cout<<mini<<endl;
            if(ans[mini]<nums[j]){
                ans.erase(ans.begin()+mini);
                ans.push_back(nums[j]);
            }
        }
        
        return ans;
    }
};