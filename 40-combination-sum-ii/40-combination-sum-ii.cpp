class Solution {
public:
    void Csum(int i, int t, vector<int>&v, vector<int>&c, vector<vector<int>>&res){
        
            if(t==0){
                res.push_back(v);
                return ;
            }
            
        
        
        for(int j=i; j<c.size(); j++){
            
                if(j>i && c[j]==c[j-1]) continue;
                if(c[j]>t) break;
        
            
                v.push_back(c[j]);
                Csum(j+1, t-c[j], v, c, res);
                v.pop_back();     
         
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>>res;
        vector<int>v;
        
        sort(candidates.begin(), candidates.end());
        
        Csum(0, target, v, candidates, res);
        
        
        return res;
    }
};