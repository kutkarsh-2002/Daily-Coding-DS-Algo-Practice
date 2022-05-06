class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        if(nums.size()==1){
            return 0;
        }
        
        long long n=nums.size();
        long long first=0, count=0, next=0, res=INT_MAX, ans=-1;
        
        for(int i=0; i<nums.size(); i++){
            next+=nums[i];
        }
        
        
        for(int i=0; i<nums.size(); i++){
            first+=nums[i];
            next-=nums[i];
            count++;
            n-=1;
            if(n==0){
                // res=min(res, abs((first/count)-0));
                if(abs((first/count)-0)<res){
                    ans=i;
                    res=abs((first/count)-0);
                }
            }else{
                
                // res=min(res, abs((first/count)-(next/n)));
                if(abs((first/count)-(next/n))<res){
                    ans=i;
                    res=abs((first/count)-(next/n));
                }
            }
        }
        
        
        
        return ans;
    }
};