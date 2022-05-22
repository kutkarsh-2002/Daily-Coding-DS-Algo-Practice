class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        
        if(stockPrices.size()==0 || stockPrices.size()==1)
            return 0;
        
        if(stockPrices.size()==2){
            return 1;
        }
        
//         //sort(stockPrices.begin(), stockPrices.end());
//         sort(stockPrices.begin() ,stockPrices.end(), []( vector<int>& u, vector<int>& v ){ return u[0] < v[0]; } );
        
//         vector<int>v;
        
//         for(int i=1; i<stockPrices.size(); i++){
//             v.push_back(stockPrices[i-1][1]-stockPrices[i][1]);
//         }
        
//         int count=1;
        
//         for(int i=1; i<v.size(); i++){
//             // if((v[i]>0 && v[i-1]<0) || (v[i]<0 && v[i-1]>0) || (v[i]==0 && v[i-1]!=0) || (v[i]!=0 && v[i-1]==0)){
//             //     count++;
//             // }
            
//             if(v[i]!=v[i-1] || (v[i]>0 && v[i-1]<0) || (v[i]<0 && v[i-1]>0) || (v[i]==0 && v[i-1]!=0) || (v[i]!=0 && v[i-1]==0)){
//                 count++;
//             }
//         }
            
//         return count;
        
        int cnt=1;
        
        sort(stockPrices.begin(),stockPrices.end());
        
        for(int i=2; i<stockPrices.size(); i++){
            long long x1=stockPrices[i-2][0], x2=stockPrices[i-1][0], x3=stockPrices[i][0];
            long long y1=stockPrices[i-2][1], y2=stockPrices[i-1][1], y3=stockPrices[i][1];
            
            long long diff1=(y2-y1)*(x3-x2);
            long long diff2=(y3-y2)*(x2-x1);
            
            if(diff1!=diff2){
                cnt++;
            }
        }
        
        return cnt;
    }
};