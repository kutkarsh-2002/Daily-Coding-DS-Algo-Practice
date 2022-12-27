class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int k) {
        vector<int>v;
        int count=0;
        
        for(int i=0; i<capacity.size(); i++){
            v.push_back(abs(capacity[i]-rocks[i]));
        }
        
        sort(v.begin(), v.end());
        
        for(int i=0; i<v.size(); i++){
            if(v[i]!=0){
                int x=(v[i]<k)?v[i]:k;
                k=k-x;
                v[i]=v[i]-x;
            }
            
            if(v[i]==0){
                count++;
            }
        }
        
        return count;
    }
};