class Solution {
public:
    
    bool check(char a, char b){
        if((a=='{' && b=='}') || (a=='[' && b==']') || (a=='(' && b==')')){
            return true;
        }
        
        return false;
    }
    
    bool isValid(string s) {
        
        if(s.size()==0){
            return true;
        }
        
        stack<char>st;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                st.push(s[i]);
            }else{
                if(st.empty()==true){
                    return false;
                }
                else if(check(st.top(), s[i])==false){
                        return false;
                }else{
                    st.pop();
                }
            }
        }
        
        return (st.empty())?true:false;
    }
};