class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        unordered_map<char, int>mps;
        unordered_map<char, int>mpt;
        
        for(int i=0; i<t.size(); i++){
            mpt[t[i]]++;
        }
        
        for(int i=0; i<s.size(); i++){
            if(mpt.find(s[i])!=mpt.end()){
                mps[s[i]]++;
            }
        }
        
        int min=INT_MAX;
        
        for(auto x:mpt){
            if(x.second>mps[x.first] || mps.find(x.first)==mps.end()){
                return 0;
            }
            
            int p=(int)(mps[x.first]/x.second);
            if(min>p){
                min=p;
            }
        }
        
//         int min=INT_MAX;
//         char temp;
        
//         for(auto x: mps){
//             cout<<x.first<<" "<<x.second<<endl;
//             if(x.second<min){
//                 min=x.second;
//                 temp=x.first;
//             }
//         }
        
        //cout<<min<<" "<<mpt[temp];
        
        return min;
    }
};