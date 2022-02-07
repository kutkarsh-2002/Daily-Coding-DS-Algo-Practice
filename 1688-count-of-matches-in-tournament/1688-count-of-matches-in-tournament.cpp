class Solution {
public:
    int ans(int n, int countM){
        if(n==1){
            return countM;
        }
        
        if(n%2==0){
            countM+=n/2;
        }else{
            countM+=(n-1)/2;
        }
        
     return (n%2==0)?ans(n/2, countM):ans((n-1)/2 +1, countM);
    }
    int numberOfMatches(int n) {
        
        int countM=0;
        return ans(n, countM);
    }
};