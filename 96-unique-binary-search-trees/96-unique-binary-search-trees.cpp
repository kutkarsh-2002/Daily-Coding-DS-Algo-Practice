class Solution {
public:
    
    long long bcf(int n, int k){
        long long res=1;
        
        if(k==0) return res;
        
        for(int i=0; i<k; i++){
            res*=(n-i);
            res/=(i+1);
        }
        
        return res;
    }
    
    int numTrees(int n) {
        //This ques can be solved by cataln number
        //Summation from i=0 to n -> CiCn-i-1
        // It is also expressed as (2nCn)/(n+1)
        
        return bcf(2*n, n)/(n+1);
        
    }
};