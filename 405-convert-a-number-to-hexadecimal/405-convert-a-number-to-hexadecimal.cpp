class Solution {
public:
    
    string toHex(int num) {
        if(num==0){
            return "0";
        }
        unsigned int n=num;
        string s="";
        while(n>0){
            int rem=n%16;
            if(rem>9){
                
                s+=('a'+rem%10);
            }
            else{
                s+=to_string(rem);
            }
            n/=16;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};