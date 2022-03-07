class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int, int>mp;
        
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        
        int j=1;
        
        while(k>0){
            if(mp.find(j)==mp.end()){
                k--;
            }
            j++;
        }
        
        return j-1;
    }
};