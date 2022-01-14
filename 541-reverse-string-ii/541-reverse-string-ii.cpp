class Solution {
public:
    string reverseStr(string s, int k) {
        /*int n=s.size();
        if(n<k){
            reverse(s.begin(), s.end());
            return s;
        }
        else if(k<=n<2k){
            int i;
            string temp="";
            for(i=0; i<n && i<k; i++){
                temp+=s[i];
            }
            reverse(temp.begin(), temp.end());
            for(; i<n; i++){
                temp+=s[i];
            }
            return temp;
        }else{
            
        }*/
        
        for (int i = 0; i < s.size(); i += 2*k) reverse(s.begin()+i, min(s.begin()+i+k, s.end()));
        return s;
    }
};