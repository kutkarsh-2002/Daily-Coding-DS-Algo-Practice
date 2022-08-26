class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        
        n=stoi(s);
        if(n&& !(n&(n-1))){
            return true;
        }
        
        sort(s.begin(), s.end());
        
        do{
            if(s[0]=='0')continue;
            n=stoi(s);
            if(n&& !(n&(n-1))){
                return true;
            }
        }while(next_permutation(s.begin(), s.end()));
        
        
        
        return false;
    }
};