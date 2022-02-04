class Solution {
public:
    long long binomialcf(int n, int k){
        long long res=1;
        if(k==0)
            return res;
        
        for(int i=0; i<k; i++){
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }
    
    vector<int> getRow(int rowIndex) {
        
        vector<int>v;
        
        for(int i=0; i<=rowIndex; i++){
            
            v.push_back(binomialcf(rowIndex, i));
            
        }
        
        return v;
    }
};