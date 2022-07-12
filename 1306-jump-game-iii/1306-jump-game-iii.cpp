class Solution {
public:
    bool check(int i, vector<int>&vis, vector<int>&arr){
        if(i<0 || i>=arr.size() || vis[i]==1) return false;
        
        if(arr[i]==0) return true;
        vis[i]=1;
        
        if(i-arr[i]>=0 && i+arr[i]<arr.size()){
            return check(i-arr[i], vis, arr)|| check(i+arr[i], vis, arr);
        }
        else if(i-arr[i]>=0)
            return check(i-arr[i], vis, arr);
        else if(i+arr[i]<arr.size())
            return check(i+arr[i], vis, arr);
        else
            return false;
    }
    
    bool canReach(vector<int>& arr, int start) {
        bool flag=false;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==0){
                flag=true;
                break;
            }
        }
        
        if(!flag) return false;
        
        vector<int>vis(arr.size(), 0);
        
        return check(start, vis, arr);
    }
};