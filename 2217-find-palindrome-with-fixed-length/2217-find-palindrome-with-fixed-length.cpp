class Solution {
public:
    
    
   /* bool isPalindrome(int n)
    {
        int rev = 0;
        for (int i = n; i > 0; i /= 10)
            rev = rev*10 + i%10;


        return (n==rev);
    }
    
    int Firstmin(int Length){
        if(Length==1){
            return 1;
        }
        else{
            return pow(10, Length - 1) + 1;
        }
        
    }
    
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        
        unordered_map<int, vector<int>>mp;
        vector<long long>res(queries.size(), 0);
        
        int count=0;
        int initial=Firstmin(intLength);
        
        for(int i=initial; i<=pow(10,intLength)-1; i++){
            if(isPalindrome(i)){
                count++;
            }
        }
        
        for(int i=0; i<queries.size(); i++){
            
            if(queries[i]>count){
                res[i]=-1;
                
            }
        
            mp[queries[i]].push_back(i);
            
        }
        
        
        count=0;
        
        for(int i=initial; i<=pow(10,intLength)-1; i++){
            
            if(isPalindrome(i)){
                count++;
            }
            
            if(isPalindrome(i) && mp.find(count)!=mp.end()){
                for(auto x:mp[count]){
                    res[x]=i;
                }
                
            }
        }
        
        return res;
        
    }*/
    
    int reverse(long long n, bool skip) {
    long long res = 0;
    for (n = skip ? n / 10 : n; n > 0; n /= 10)
        res = res * 10 + n % 10;
    return res;
}
    
vector<long long> kthPalindrome(vector<int>& queries, int sz) {
    vector<long long> res;
    long long start = pow(10, (sz + 1) / 2 - 1), end = pow(10, (sz + 1 ) / 2), mul = pow(10, sz / 2);    
    for (int q : queries)
        res.push_back(start + q > end ? -1 : 
            (start + q - 1) * mul + reverse(start + q - 1, sz % 2));
    return res;
}
};