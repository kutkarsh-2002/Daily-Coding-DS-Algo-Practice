// class Solution {
// public:
//     int minSetSize(vector<int>& arr) {
        
//     }
// };

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> hash;
        vector<int> vec;
        int ans = 0, s = 0;
        for(int i:arr) hash[i]++;
        for(auto [a,b]:hash) vec.push_back(b);
        sort(vec.begin(),vec.end(),greater<int>());
        for(int i=0;i<vec.size() && s*2<arr.size(); ++i) ans++, s += vec[i];
        return ans;
    }
};