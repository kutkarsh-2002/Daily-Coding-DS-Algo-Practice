class Solution {
public:
    
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<int>indg(n+1, 0);
       vector<int>outdg(n+1, 0);
       
        for(int i=0; i<trust.size(); i++){
            indg[trust[i][1]]++;
            outdg[trust[i][0]]++;
        }
        
        for(int i=1; i<=n; i++){
            if(indg[i]==n-1 && outdg[i]==0){
                return i;
            }
        }
        
        return -1;
    }
};