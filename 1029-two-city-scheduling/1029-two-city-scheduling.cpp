class Solution {
public:
    static bool com(int a, int b){
        return a>b;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        /*int aCost=0, bCost=0;
        
        for(int i=0; i<costs.size(); i++){
            if(costs[i][0]<costs[i][1]){
                aCost+=costs[i][0];
            }
            else{
                bCost+=costs[i][1];
            }
        }
        
        return aCost+bCost;*/
        
        vector<int>refund;
        int ans=0;
        
        for(auto it:costs){
            ans+=it[0];
            refund.push_back(it[0]-it[1]);
        }
        
        sort(refund.begin(), refund.end(), com);
        
        for(int i=0; i<refund.size()/2; i++){
            ans-=refund[i];
        }
        
        return ans;
    }
};