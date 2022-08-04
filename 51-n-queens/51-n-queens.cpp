class Solution {
public:
    
    /*********************************************************/
//     To place Q at the right position and following the rules of the chess board 3 condition must be satisfied.
    
//     1. Every row must have Q
//     2. Every col must have Q
//     3. One Q should not attack other Q
        
//     Note: In chess board Q can attack in 8 directions.
        
//         lupdiag(row--, col--), llowdia(row++, col--), up(row--, col), dn(row++, col), riupdiag(row--, col++), rilowdiag(row++, col++), left(row, col--), right(row, col++);
    
//     But in this case just we need to check for left upper diagonal, left lower diagonal, and left side because in else direction cells will be unfilled. So we will never get Q on such cells.
    
    /***********************************************************/
    
//     bool isValid(int row, int col, int n, vector<string>&board){
//         int dprow=row, dpcol=col;
        
//         //upper diag
//         while(row>=0 && col>=0){
//             if(board[row][col]=='Q') return false;
//             row--;
//             col--;
//         }
        
//         row=dprow, col=dpcol;
        
//         //lower diag
//         while(row<n && col>=0){
//             if(board[row][col]=='Q') return false;
//             row++;
//             col--;
//         }
        
//         //left row
//         col=dpcol;
//         row=dprow;
//         while(col>=0){
//             if(board[row][col]=='Q') return false;
//             col--;
//         }
        
//         return true;
//     }
    
//     void dfs(int col, int n, vector<string>&board, vector<vector<string>>&res){
//         if(col==n){
//             //if col==n i.e we have successfully placed Q at the right position
//             // so we will push board into result.
//             res.push_back(board);
//             return ;
//         }
        
//         for(int row=0; row<n; row++){
//             // for every col we will check into each row that is it posiible to place Q until we get the right pos.
            
//             if(isValid(row, col, n, board)){
//                 board[row][col]='Q';
//                 dfs(col+1, n, board, res);
//                 board[row][col]='.';
//             }
//         }
//     }
    
//     vector<vector<string>> solveNQueens(int n) {
        
//         if(n==0) return {{}};
//         vector<vector<string>>res;
//         vector<string>board(n);
//         string s(n, '.');
        
//         for(int i=0; i<n; i++){
//             board[i]=s;
//         }
        
//         dfs(0, n, board, res);
//         return res;
//     }
    
    
    /***********************************************/
    
//     In order to optimize the code we need to use the concept of hashing.
//     We will create 3 vector in order to have a track of cell containing Q.
//     1. updiag -> size-> 2*n-1
//     2. lowdiag -> size -> 2*n-1
//     3. left ->   size ->  n
        
//     Note: In order to fill the various vector array use this formula.
        
//         updiag[n-1+col-row]=1
//         lowdiag[row+col]=1
//         lrow[row]=1
        
    
    
    /*********************************************/
    
       
    void dfs(int col, int n, vector<string>&board, vector<int>&updiag, vector<int>&lowdiag, vector<int>&lrow, vector<vector<string>>&res){
        if(col==n){
            //if col==n i.e we have successfully placed Q at the right position
            // so we will push board into result.
            res.push_back(board);
            return ;
        }
        
        for(int row=0; row<n; row++){
            // for every col we will check into each row that is it posiible to place Q until we get the right pos.
            
            if(lrow[row]==0 && updiag[n-1+col-row]==0 && lowdiag[row+col]==0){
                board[row][col]='Q';
                updiag[n-1+col-row]=1;
                lowdiag[row+col]=1;
                lrow[row]=1;
                dfs(col+1, n, board, updiag, lowdiag, lrow, res);
                board[row][col]='.';
                updiag[n-1+col-row]=0;
                lowdiag[row+col]=0;
                lrow[row]=0;
            }
            
        }
    }
       vector<vector<string>> solveNQueens(int n) {
        
        if(n==0) return {{}};
        vector<vector<string>>res;
        vector<string>board(n);
        string s(n, '.');
        
        for(int i=0; i<n; i++){
            board[i]=s;
        }
        
        vector<int>updiag(2*n-1, 0), lowdiag(2*n-1, 0), lrow(n, 0);
        dfs(0, n, board, updiag, lowdiag, lrow, res);
        return res;
    }
};

