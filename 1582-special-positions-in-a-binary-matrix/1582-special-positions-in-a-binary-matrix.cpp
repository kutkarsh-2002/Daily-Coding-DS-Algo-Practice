class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int count=0;
        
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                int sumR=0, sumC=0;
                
                for(int p=0; p<mat[0].size(); p++){
                    sumC+=mat[i][p];
                }
                
                for(int q=0; q<mat.size(); q++){
                    sumR+=mat[q][j];
                }
                
                if(sumR==1 && sumC==1 && mat[i][j]==1){
                    count++;
                    //cout<<i<<" "<<j<<endl;
                }
            }
        }
        
        return count;
    }
};