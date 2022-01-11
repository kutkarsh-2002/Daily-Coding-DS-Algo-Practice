class Solution {
public:
    /*bool isUgly(int n) {
        if(n<14){
            return true;
        }
        if(n<0){
            n=-n;
        }
        for(int i=2; i<=n/2; i++){
            if((n%(6*i-1)==0 || n%(6*i+1)==0) || n%7==0){
                return false;
            }
        }
        return true;
    }*/
    
    bool isUgly(int n) {
        while(n!=1){
            int temp = n;
            if(n%2 == 0){
                n/=2;
            }
            
            if(n%3 == 0){
                n/=3;
            }
            
            if(n%5 == 0){
                n/=5;
            }
            
            if(temp == n){
                return 0;
            }
    
        }
        
        return 1;
    }
};