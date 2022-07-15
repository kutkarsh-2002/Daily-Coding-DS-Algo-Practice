class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<0) return true;
        long long l=0, r=sqrt(c);
        
        while(l<=r){
            long long num=l*l+r*r;
            
            if(num==c) return true;
            else if(num>c) r--;
            else
                l++;
        }
        
        return false;
    }
};