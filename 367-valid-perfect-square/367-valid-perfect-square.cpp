class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num==1)
            return true;
        int st=1, end=num;
        
        while(st<=end){
            long long int mid=st+(end-st)/2;
            
            if(mid*mid==num)
                return true;
            else if(mid*mid>num)
                end=mid-1;
            else
                st=mid+1;
        }
        
        return false;
    }
};