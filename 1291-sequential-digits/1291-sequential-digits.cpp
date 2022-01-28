class Solution {
public:
    /*bool findingDigits(int num){
        int prev=num%10;
        num/=10;
        while(num>0){
            int curr=num%10;
            if((curr+1)!=prev){
                return false;
            }
            prev=curr;
            num/=10;
        }
        
        return true;
    }
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int>v;
        
        for(int i=low; i<=high; i++){
            if(findingDigits(i)){
                v.push_back(i);
            }
        }
        
        return v;
    }*/
    
    void dfs(int low, int high, int i, int num, vector<int>&res){
        if(num>=low && num<=high){
            res.push_back(num);
        }
        if(num>high || i>9){
            return ;
        }
        dfs(low, high, i+1, num*10+i, res);
    }
    
    vector<int> sequentialDigits(int low, int high){
        vector<int>res;
        for(int i=1; i<=9; i++){
            dfs(low, high, i, 0, res);
        }
        sort(res.begin(), res.end());
        return res;
    }
    
};