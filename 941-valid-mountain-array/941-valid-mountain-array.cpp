class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3){
            return false;
        }
        
        bool flag=true;
        
        for(int i=1; i<arr.size(); i++){
            if(arr[i-1]<=arr[i] && flag==false){
                return false;
            }else if(arr[i-1]>arr[i] && flag==true && i!=1){
                flag=false;
            }else if(arr[i-1]>=arr[i] && flag==true){
                return false;
            }
        }
        if(flag==true){
            return false;
        }
        
        return true;
    }
};