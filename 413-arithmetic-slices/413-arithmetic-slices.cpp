class Solution {
public:
    int dp[5001]={0};
    int numberOfArithmeticSlices(vector<int>& arr) {
        
        int n = arr.size(); // extracting the size of the array
        
        if(n < 3) // if the size of the array is less than 3,
        {
            return 0; // then answer is not possible, simply return 0
        }
        
        // for the first subarray
        if(arr[2] - arr[1] == arr[1] - arr[0])
        {
            dp[2] = 1;
        }
        
        int ans = 0;  // variable that stores our final answer
        
        // start traversing from the loop
        for(int i = 2; i < n; i++)
        {
            // for curremt element check difference with previous elements
            if(arr[i] - arr[i - 1] == arr[i - 1] - arr[i - 2])
            {
                // if difference is same increase dp[i] by 1
                dp[i] = dp[i - 1] + 1; 
            }
            
            // and add to our answer
            ans = ans + dp[i];
        }
        
        return ans; // finally return answer
        
    }
};