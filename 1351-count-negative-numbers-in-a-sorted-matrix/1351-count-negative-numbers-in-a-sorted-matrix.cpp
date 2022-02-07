class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int j=0;
        int i=n-1;
        int count=0;
        
        while(i>=0 && i<n && j>=0 && j<m){
            if(grid[i][j]<0){
                count+=m-j;
                i=i-1;
            }else{
                j=j+1;
            }
        }
        
        return count;
    }
};