class Solution {
public:
    
    int t[3][1001];
    
    int helper(int k, int n){
        
        // your code here
        if(n==0 || n==1){
            return n;
        }
        if(k==1){
            return n;
        }
        
        if(t[k][n]!=-1){
            return t[k][n];
        }
        
        int ans=INT_MAX;;
        
        for(int i=1; i<=n; i++){
            int low=0, high=0;
            
            if(t[k-1][i-1] !=-1){
                low=t[k-1][i-1];
            }
            else{
                low=helper(k-1, i-1);
                t[k-1][i-1]=low;
            }
            if(t[k][n-i] !=-1){
                high=t[k][n-i];
            }
            else{
                high=helper(k, n-i);
                t[k][n-i]=high;
            }
            
            int temp=1+max(low,high);
            // int temp=1+max(eggDrop(n-1, i-1), eggDrop(n, k-i));
            
            ans=min(ans, temp);
        }
        
        return t[k][n]=ans;
        // return ans;
    }
    
    int twoEggDrop(int n) {
        
        memset(t, -1, sizeof(t));
        
        return helper(2, n);
    }
};