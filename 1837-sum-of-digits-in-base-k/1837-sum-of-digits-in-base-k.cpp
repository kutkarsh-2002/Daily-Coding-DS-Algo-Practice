class Solution {
public:
    int sumBase(int n, int k) {
        
        string s="";
        
        while(n>0){
            int rem=n%k;
            s+=to_string(rem);
            n/=k;
        }
        
        reverse(s.begin(), s.end());
        int res=stoi(s);
        
        int ans=0;
        while(res>0){
            int rem=res%10;
            ans+=rem;
            res/=10;
        }
        return ans;
    }
};