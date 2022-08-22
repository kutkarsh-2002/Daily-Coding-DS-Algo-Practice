class Solution {
public:
    int findTheWinner(int n, int k) {
        int f=0;
        
        for(int i=2; i<=n; i++){
            f=(f+k)%i;
        }
        
        return f+1;
    }
};