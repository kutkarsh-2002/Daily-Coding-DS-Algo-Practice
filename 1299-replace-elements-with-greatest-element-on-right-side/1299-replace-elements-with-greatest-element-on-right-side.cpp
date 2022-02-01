class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int mg=-1;
        int n=arr.size();
        vector<int>v;
        v.push_back(-1);
        for(int i=n-2; i>=0; i--){
            mg=max(mg, arr[i+1]);
            v.push_back(mg);
            
        }
        
        reverse(v.begin(), v.end());
        
        return v;
    }
};