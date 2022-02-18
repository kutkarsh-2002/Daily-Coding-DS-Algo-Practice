class Solution {
public:
    /*bool isPrime(int num){
        if(num<=1)
            return false;
        if(num==2 || num==3)
            return true;
        
        if(num%2==0 || num%3==0)
            return false;
        
        for(int i=5; i*i<=num; i+=6){
            if(num%i==0 || num%(i+2)==0)
               return false;
        }
               
        return true;
    }*/
    
    
    int countPrimes(int n) {
        
        if(n == 0 || n == 1) return 0;
        vector<bool>primes(n+1, true);
        primes[0] = primes[1] = false;
        for(int i = 2; i*i <= n; i++)
            if(primes[i])
                for(int j = 2; i*j <= n; j++)
                    primes[i*j] = false;
        
        int ans = 0;
        for(int i = 2; i < n; i++)
            if(primes[i]) ans++;
        return ans;   
    }
};