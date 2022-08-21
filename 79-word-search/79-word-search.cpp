class Solution {
public:
    
    bool dfs(int i, int j, int l, vector<vector<char>>& board, string &word, vector<vector<int>>&vis){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[l-1] || vis[i][j]==1) return false;
        
        vis[i][j]=1;
        
        if(l==word.size()) return true;
        
        if(dfs(i-1, j, l+1, board, word, vis) || dfs(i+1, j, l+1, board, word, vis) || dfs(i, j-1, l+1, board, word, vis) || dfs(i, j+1, l+1, board, word, vis)){
            return true;
        }
    
        
        vis[i][j]=0;
       
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        vector<vector<int>>vis(board.size(), vector<int>(board[0].size(), 0));
        
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(word[0]==board[i][j]){
                    if(dfs(i, j, 1, board, word, vis)) return true;
                }
            }
        }
        
        return false;
        
    }
};