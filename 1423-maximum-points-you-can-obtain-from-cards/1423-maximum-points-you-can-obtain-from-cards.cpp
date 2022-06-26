// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
        
//     }
// };

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total_sum = 0;
        // calculate the sum of all the elements in the array
        for(auto i : cardPoints)
            total_sum += i;
        
        int window = 0; // used to store temporary sum
        int n = cardPoints.size();
        int left = 0;
        int right = n - k;
        
        // if size of array equals k, entire array is considered as the window so return total sum
        if(n==k)
            return total_sum;
        
        // calculate the sum of 1st window
        for(int i=0;i<right;i++)
        {
            window += cardPoints[i];
        }
        int ans = total_sum - window;
        
        // start using sliding window
        while(right < n){
            window -= cardPoints[left++];
            window += cardPoints[right++];
            
            // calculate the max sum
            ans = max(total_sum - window, ans);
        }
        
        return ans;
    }
};