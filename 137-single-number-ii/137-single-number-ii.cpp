class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
      int n = nums.size();
      int arr[32];
      memset(arr, 0, sizeof(arr));

      for(int i=0; i<n; i++){
        for(int j=0; j<32; j++){
          arr[j] += nums[i]&1;
          nums[i] >>= 1;
          if(nums[i] == 0)
            break;
        }
      }
        
      int x = 0;
      for(int i=0; i<32; i++){
        arr[i] %= 3;
        if(arr[i] == 1){
          x |= 1 << i;
        }
      }
      return x;
    }
};