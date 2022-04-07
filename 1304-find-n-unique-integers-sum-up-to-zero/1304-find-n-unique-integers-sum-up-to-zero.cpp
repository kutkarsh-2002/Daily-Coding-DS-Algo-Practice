class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1){
            return {0};
        }
        if(n==1){
            return {1,-1};
        }
        
        vector<int>v;
        int i=0;
        while(n>0){
            if(i==0 && n%2!=0){
                v.push_back(i);
                n--;
            }
            else{
                i=i+1;
                v.push_back(i);
                v.push_back(-i);
                n=n-2;
            }
            i++;
        }
        
       return v; 
    }
};