class Solution {
public:
//     double result=1;
//     double myPow(double x, int n) {
//         if(n==0){
//             result*=1;
//             return result;
//         }
//         if(n!=0 && n>0){
//             result *=x;
//         }
//         else if(n!=0 && n<0){
//             result *= 1/x;
//         }
        
//        if(n>=0){
//            myPow(x,n-1);
//        }else{
//           myPow(x,n+1);
//        }
//         return result;
//     }
    
    
    double myPow(double x, int n){
        double res=1;
        bool flag=n>0;
            while(n!=0){
            if((n&1)!=0){
                res=res*x;
            }
            x=x*x;
            n=n/2;
                
        }
        
        if(flag)
            return res;
        
        else
            return 1/res;
         
       
    }
};