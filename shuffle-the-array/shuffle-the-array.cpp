class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>arr(2*n);
        
//         vector<int>arr;
//         int i= 0 ,j =n ;
//         while(i<n && j< nums.size()) {
//             arr.push_back(nums[i]);
//             arr.push_back(nums[j]) ;
//             i++;
//             j++;
//         }
        
        
        for(int i=0; i<n; i++){
            arr[2*i]=nums[i];
            arr[2*i+1]=nums[n+i];
        }
        
        return arr;
        
    }
};