class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        vector<int>ans;
        
        for(int j=0; j<grid[0].size(); j++){
            
            int i=0, k=j;
            bool flag=false;
            
            while(k>=0 && i<grid.size() && k<grid[0].size()){
                if(k==0 && grid[i][k]==-1){
                    flag=true;
                    break;
                }
                else if(k==grid[0].size()-1 && grid[i][k]==1){
                    flag=true;
                    break;
                }
                else if(k+1<grid[0].size() && grid[i][k]==1 && grid[i][k+1]==-1){
                    flag=true;
                    break;
                }
                else if(k-1>=0 && grid[i][k]==-1 && grid[i][k-1]==1){
                    flag=true;
                    break;
                }
                else if(grid[i][k]==1){
                    i=i+1;
                    k=k+1;
                }
                else if(grid[i][k]=-1){
                    i=i+1;
                    k=k-1;
                }
                
            }
            
            if(flag){
                ans.push_back(-1);
            }
            else{
                ans.push_back(k);
            }
        }
        
        return ans;
    }
};