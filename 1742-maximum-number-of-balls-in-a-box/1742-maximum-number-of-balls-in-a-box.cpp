class Solution {
public:
    int SumofDigit(int num){
        int sum=0;
        while(num>0){
            int rem=num%10;
            sum+=rem;
            num/=10;
        }
        
        return sum;
    }
    int countBalls(int lowLimit, int highLimit) {
        
        unordered_map<int, int>mp;
        
        for(int i=lowLimit; i<=highLimit; i++){
           
            mp[SumofDigit(i)]++;
        }
        
        int freq=0;
        
        for(auto x:mp){
            
            freq=max(freq, x.second);
            
        }
        
        return freq;
    }
};