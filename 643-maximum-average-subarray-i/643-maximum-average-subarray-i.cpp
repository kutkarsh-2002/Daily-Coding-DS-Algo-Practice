class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       
        
        double ans=INT_MIN;
        int i=0, j=0;
        long long sum=0;
        
        while(i<nums.size() && j<nums.size()){
            sum+=nums[j];
           
            if((j-i)+1==k){
                ans=max(ans, (double)sum/k);
                sum-=nums[i];
                i++;
                j++;
            }else{
                j++;
            }
        }
        
        return ans;
    }
};