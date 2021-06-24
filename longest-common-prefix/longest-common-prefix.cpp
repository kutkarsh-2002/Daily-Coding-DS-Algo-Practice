class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
//         if(strs.size()==0){
//             return "";
//         }
//         string s1 = "";
//         string s2 = "";
//         int result=INT_MAX;
//         for(int k=0; k<strs.size()-1; k++){
//             s1=strs[k];
//             s2=strs[k+1];
//             int i=0, j=0, count=0;
//             while(i<s1.length() && j<s2.length()){
//                 if(s1[i]!=s2[j]){
//                     break;
//                 }
//                 else{
//                     count++;
//                     i++;
//                     j++;
//                 }
                
//             }
//             result=min(count, result);
//         }
//         string res = "";
//         if(result>0){
//             for(int i=0; i<result; i++){
//                 res=res+s2[i];
//             }
            
//         }
//         return res;
        
        string res = "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[0][i] != strs[j][i]) {
                    return res;
                }
            }
            res += strs[0][i];
        }
        return res;
        
    }
};