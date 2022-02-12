class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int res=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>arr[i+1])
            {
                res=i;
                break;
            }
        }
        
        return res;
    }
};