class Solution {
public:
    static bool cmp(pair<int, int>&a, pair<int, int>&b){
        if(a.second<b.second) return true;
        if(a.second>b.second) return false;
        
        if(a.second==b.second){
            return a.first<b.first;
        }
        
        return false;
    }
    
    
    int cntSetbits(int n){
        int res=0;
        cout<<n<<" ";
        while(n>0){
            n=n&(n-1);
            res++;
        }
        //cout<<res<<endl;
        return res;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        //sort(arr.begin(), arr.end());
        vector<pair<int, int>>res;
        
        for(int i=0; i<arr.size(); i++){
            res.push_back({arr[i], cntSetbits(arr[i])});
        }
        
        sort(res.begin(), res.end(), cmp);
        arr.clear();
        for(int i=0; i<res.size(); i++){
            arr.push_back(res[i].first);
        }
        
        return arr;
        
    }
};