class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if(poured==0){
            return (double)poured;
        }
        
        vector<vector<double>> v(102, vector<double>(102, 0.0));
        
        v[0][0]=poured;
        
        for(int i=0; i<query_row; i++){
            
            for(int j=0; j<=i; j++){
                
                double flow=(v[i][j]-1)/2.0;
                cout<<flow<<""<<endl;
                
                if(flow>0){
                    
                    v[i+1][j]+=flow;
                    v[i+1][j+1]+=flow;
                }
            }
        }
        
        cout<<v[1][1];
        return min(1.0, v[query_row][query_glass]);
    }
};