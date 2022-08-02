class Solution {
public:
//     vector<int>curr;
//     vector<vector<int>>res;
//     int sum;
    
//    void find(vector<int>&candidates, int target, int index){
//         if(sum>target)
//             return;
        
//         if(sum==target)
//             res.push_back(curr);
       
//        for(int i=index; i<candidates.size(); i++){
//            sum+=candidates[i];
//            curr.push_back(candidates[i]);
//            find(candidates, target, i);
//            sum-=candidates[i];
//            curr.pop_back();
//        }
//     }
    
    void Csum(int i, vector<int>&v, vector<int>& c, int t, vector<vector<int>>&res){
        if(i==c.size()){
            if(t==0){
                res.push_back(v);
            }
            return ;
        } 
        
        //take
        if(c[i]<=t){
            v.push_back(c[i]);
            t-=c[i];
            Csum(i, v, c, t, res);
            t+=c[i];
            v.pop_back();
        }
        
        
        //not take
        Csum(i+1, v, c, t, res);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
//         sum=0;
//         find(candidates, target, 0);
        
//         return res;
        
        vector<vector<int>>res;
        vector<int>v;
        
        Csum(0, v, candidates, target, res);
        
        return res;
    }
};