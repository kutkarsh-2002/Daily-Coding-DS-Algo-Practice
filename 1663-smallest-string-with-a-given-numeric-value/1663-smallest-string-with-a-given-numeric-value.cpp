class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string res(n,'a');
        for(int i=0;i<n;++i){
            int remain=k-(n-1-i);
            if(remain>=26)  res[n-1-i]='z' , k-=26;
            else res[n-1-i]=char('a'+remain-1) , k=n-i-1;
        }
        return res;
    }
};