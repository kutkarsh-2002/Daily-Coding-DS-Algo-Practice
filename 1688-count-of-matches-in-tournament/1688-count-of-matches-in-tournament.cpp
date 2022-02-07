class Solution {
public:
    /*int ans(int n, int countM){
        if(n==1){
            return countM; //if no. of team is equal to 1 then no matched will be played so simply return countM which is base case.
        }
        
        if(n%2==0){
            countM+=n/2; //count the number of matches in case number of team is even.
        }else{
            countM+=(n-1)/2; //count the number of matches in case number of team is odd.
        }
        
     return (n%2==0)?ans(n/2, countM):ans((n-1)/2 +1, countM); //pass n/2 in function if no. of teams is even else pass (n-1)/2 +1 if no. of teams is odd.
    }
    int numberOfMatches(int n) {
        
        int countM=0;
        return ans(n, countM);
    }*/
    
    int numberOfMatches(int n) {
        
       
        return (n-1);
    }
    
};