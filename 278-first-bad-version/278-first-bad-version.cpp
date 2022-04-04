// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long i=1, j=n, mid=0, ans=0;
        
        while(i<=j){
            mid=(i+j)/2;
            if(isBadVersion(mid)==false){
                i=mid+1;
                
            }
            else if(isBadVersion(mid)){
                ans=mid;
                j=mid-1;
            }
            
             
        }
        
        return ans;
        
    }
};