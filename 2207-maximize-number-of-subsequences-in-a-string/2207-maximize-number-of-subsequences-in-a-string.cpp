class Solution {
public:
    
    long long count(string a, string b)

    {
    long long m = a.length();
    long long n = b.length();
 
    // Create a table to store results of sub-problems
    long long dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
 
    // If first string is empty
    for (long long i = 0; i <= n; ++i)
        dp[0][i] = 0;
 
    // If second string is empty
    for (long long i = 0; i <= m; ++i)
        dp[i][0] = 1;
 
    // Fill dp[][] in bottom up manner
    for (long long i = 1; i <= m; i++)
    {
        for (long long j = 1; j <= n; j++)
        {
            // If last characters are same, we have two
            // options -
            // 1. consider last characters of both strings
            //    in solution
            // 2. ignore last character of first string
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] +
                               dp[i - 1][j];
                 
            else
                // If last character are different, ignore
                // last character of first string
                dp[i][j] = dp[i - 1][j];
        }
    }
 
    return dp[m][n];
}
    long long maximumSubsequenceCount(string text, string pattern) {
        
        long long res=0;
        
        string text1=pattern[0]+text;
        if(res<count(text1, pattern)){
            res=count(text1, pattern);
        }
        
        string text2=text+pattern[0];
        //res=max(res, count(text2, pattern));
        if(res<count(text2, pattern)){
            res=count(text2, pattern);
        }
        
        string text3=pattern[1]+text;
        //res=max(res, count(text3, pattern));
        
        if(res<count(text3, pattern)){
            res=count(text3, pattern);
        }
        
        string text4=text+pattern[1];
        //res=max(res, count(text4, pattern));
        
        if(res<count(text4, pattern)){
            res=count(text4, pattern);
        }
        
        return res;
        
    }
};