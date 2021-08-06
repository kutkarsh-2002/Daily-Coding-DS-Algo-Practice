class Solution {
public:
    int firstUniqChar(string s) {
        
        // for(int i=0; i<s.size()-1; i++){
        //     int count=0;
        //     for(int j=i+1; s.size(); j++ ){
        //         if(s[i]==s[j]){
        //             count++;
        //         }
        //     }
        // }
        // vector<string>v(256);
        // int mi=INT_MAX;
        // fill(v.begin(), v.end(), false);
        // for(int i=s.end()-1; i>=0; i--){
        //     if(v[s[i]]==false){
        //         v[s[i]]=true;
        //     }else{
        //         mi=min(mi, i);m
        //     }
        // }
        vector<int>v(256);
        fill(v.begin(), v.end(), -1);
        for(int i=0;i<s.size(); i++){
            if(v[s[i]]==-1){
                v[s[i]]=i;
            }else{
                v[s[i]]=-2;
            }
        }
        int mi=INT_MAX;
        for(int i=0; i<256; i++){
            if(v[i]>=0){
                mi=min(mi, v[i]);
            }
        }
        return mi<INT_MAX?mi:-1;
    }
};