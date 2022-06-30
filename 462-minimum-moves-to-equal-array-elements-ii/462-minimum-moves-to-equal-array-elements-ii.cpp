class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        
//         int median=(n%2==0)?((nums[n/2]+nums[((n/2)+1)/2])/2):nums[n/2];
        
//         if(n%2==0){
//             median=nums[n/2];
//         }
//         cout<<median<<endl;
         long long ans=0;
        
        int median=nums[n/2];
        for(int i=0; i<n; i++){
            ans+=abs(median-nums[i]);
        }
        
        return ans;
    }
};