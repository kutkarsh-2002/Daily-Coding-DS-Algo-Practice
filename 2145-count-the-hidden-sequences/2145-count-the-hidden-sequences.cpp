class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        // a   a+1  a-2  a+2
        //   -1   -3    4
        // min=a-2
        // max=a+2
        //a-2=lower => a=1+2=3
        //a+2=upper => a=6-2=4
        //Range={3, 4}
        
        long long sum=0, mx=0, mi=0;
        
        for(int i=0; i<differences.size(); i++){
            sum+=differences[i];
            mi=min(mi, sum);
            mx=max(mx, sum);
        }
        
        long long l=lower-mi, u=upper-mx;
        
        return (u-l+1>0)?(u-l+1):0;
    }
};