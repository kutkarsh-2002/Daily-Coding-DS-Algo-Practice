class Solution {
public:
    vector<int>curr;
    vector<vector<int>>res;
    int sum;
    
   void find(vector<int>&candidates, int target, int index){
        if(sum>target)
            return;
        
        if(sum==target)
            res.push_back(curr);
       
       for(int i=index; i<candidates.size(); i++){
           sum+=candidates[i];
           curr.push_back(candidates[i]);
           find(candidates, target, i);
           sum-=candidates[i];
           curr.pop_back();
       }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        find(candidates, target, 0);
        
        return res;
    }
};