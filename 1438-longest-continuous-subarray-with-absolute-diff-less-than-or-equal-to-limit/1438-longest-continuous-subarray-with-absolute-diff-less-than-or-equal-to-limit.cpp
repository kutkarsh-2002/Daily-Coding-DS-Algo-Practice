class Solution {
public:
    int longestSubarray(vector<int>& nums, int l) {
        int res=0, mx, mi;
        priority_queue<pair<int, int>>pmx;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pmi;
        
        int i=0, j=0;
        
        while(j<nums.size()){
            pmx.push({nums[j], j});
            pmi.push({nums[j], j});
            
            while(pmx.top().second<i){
                pmx.pop();
            }
            while(pmi.top().second<i){
                pmi.pop();
            }
            
            if(pmx.top().first-pmi.top().first<=l){
                res=max(res, j-i+1);
                j++;
            }else{
                i++;
                j++;
            }
        }
        
        return res;
    }
};