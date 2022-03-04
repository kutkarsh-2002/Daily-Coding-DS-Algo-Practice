class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        
        if(A.size()==0 || A.size()==1)
            return {};
        
        unordered_map<char, int> ansMap;
        unordered_map<char, int> midMap;
        vector<string> res;
        for(auto c : A[0]) {
            ansMap[c]++;
        }
        
        if(ansMap.size()==0)
            return res;
        
        for (auto i = 1; i < A.size() ; ++i) {
            midMap.clear();
            for (auto c : A[i]) {
                midMap[c]++;
            }
            if (midMap.size() == 0) {
                return res;
            }
            for (auto iter = ansMap.begin(); iter != ansMap.end();iter++) {
                if (midMap.count(iter->first)) { 
                    ansMap[iter->first] = min(ansMap[iter->first], midMap[iter->first]);
                }
                else {
                    ansMap[iter->first] = 0;
                }
            }
        }
        
        for (auto iter = ansMap.begin(); iter != ansMap.end(); iter++) {
            for (auto i = 0; i < ansMap[iter->first]; ++i) {
                res.push_back(string(1, iter->first));
            }
        }
           
        return res;
        
        
    }
};