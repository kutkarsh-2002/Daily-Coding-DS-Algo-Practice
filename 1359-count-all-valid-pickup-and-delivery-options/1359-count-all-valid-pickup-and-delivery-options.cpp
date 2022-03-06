class Solution {
public:
    int fun(int n){
        long long sum=(n*(n+1))/2;
        return sum%(1000000007);
    }
    int countOrders(int n) {
        vector<long long>dp(n+1,0);
        dp[0]=0; dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=(fun(2*i-1)*(dp[i-1]%(1000000007)))%(1000000007);
        }
        int ans= dp[n]%(1000000007);
        return ans;
    }
};