class Solution {
public:
    static bool cmp(const vector<int>& v1, const vector<int>& v2){
        return v1[1]>v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        long long ans=0;
        
        for(int i=0; i<boxTypes.size() && truckSize>0; i++){
            if(boxTypes[i][0]<=truckSize){
                ans+=(boxTypes[i][0]*boxTypes[i][1]);
                truckSize-=boxTypes[i][0];
            }
            else if(boxTypes[i][0]>truckSize){
                ans+=truckSize*boxTypes[i][1];
                truckSize=0;
            }
        }
        
        return ans;
    }
};