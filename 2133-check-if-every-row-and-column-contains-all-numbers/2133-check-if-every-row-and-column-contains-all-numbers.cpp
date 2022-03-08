class Solution {
public:
    /* Idea of the problem
    1.Use for loops to check each row for every number from 1 to n. Similarly, do the same for each column.
    2.For each check, you can keep a set of the unique elements in the checked row/col. By the end of the check, the size of the set should be n.
    */
    
    bool checkValid(vector<vector<int>>& matrix) {
        unordered_set<int>st;
        int col=0, n=matrix.size();
        
        for(int row=0; row<n; row++){
            
            //j is column traversing for each row
            
            for(int j=0; j<n; j++){
                if(matrix[row][j]>=1 && matrix[row][j]<=n){
                    st.insert(matrix[row][j]);
                }
            }
            if(st.size()!=n)
                return false;
            
            st.clear();
            
            //i is row traversing for each col(column)
            
            for(int i=0; i<n; i++){
                if(matrix[i][col]>=1 && matrix[i][col]<=n){
                    st.insert(matrix[i][col]);
                }
            }
            
            if(st.size()!=n)
                return false;
            
            st.clear();
            col=row+1;
        }
        
        return true;
    }
};