class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_set<string>st;
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                
                if(board[i][j]!='.'){
                    int Box=(i/3)*3+(j/3);
                    string tempBox="Box"+to_string(Box)+board[i][j];
                    string tempRow="Row"+to_string(i)+board[i][j];
                    string tempCol="Col"+to_string(j)+board[i][j];
                    
                    if(st.find(tempBox)!=st.end() || st.find(tempRow)!=st.end() || st.find(tempCol)!=st.end()){
                        return false;
                    }else{
                        st.insert(tempBox);
                        st.insert(tempRow);
                        st.insert(tempCol);
                    }
                }
                
            }
        }
        
        return true;
    }
};