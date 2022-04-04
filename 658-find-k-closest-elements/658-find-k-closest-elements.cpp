class Solution {
public:
    // bool comp(const auto a, const auto b, const auto x){
    //     return abs(a-x)<abs(b-x);
    // }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        stable_sort(arr.begin(), arr.end(), [x](const auto a, const auto b){
            return abs(a - x) < abs(b - x);
        }); //sort by distance;
        
        arr.resize(k);
        
        sort(arr.begin(), arr.end());
        return arr;
            
    }
        
};