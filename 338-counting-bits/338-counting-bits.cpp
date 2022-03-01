class Solution {
public:
    
    int countsetbits(int i){
        int res=0;
        while(i>0){
            i=(i&(i-1));
            res++;
        }
        
        return res;
    }
    vector<int> countBits(int n) {
        
        vector<int>v;
        
        for(int i=0; i<=n; i++){
            v.push_back(countsetbits(i));
        }
        
        return v;
    }
};