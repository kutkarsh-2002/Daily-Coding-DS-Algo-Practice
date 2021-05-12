class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>arr(2*n);
        // int temp=0;
        // int j=n;
        // for(int i=0; i<=n+1; i=i+2){
        //     while(temp<n && j<2*n) {
        //         arr[i]=nums[temp];
        //         arr[i+1]=nums[j];
        //         temp++;
        //         j++;
        //     }
        // }
        for(int i=0; i<n; i++){
            arr[2*i]=nums[i];
            arr[2*i+1]=nums[n+i];
        }
        
        return arr;
        
    }
};