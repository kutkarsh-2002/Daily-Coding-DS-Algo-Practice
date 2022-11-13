class Solution {
public:
    string reverseWords(string s) {
        
//         string temp="";
//         string res="";
//         bool flag=false;
        
//         for(int i=s.size()-1; i>=0; i--){
            
//             if(s[i]==' ' && flag==false){
//                 continue;
//             }
            
//             else if(s[i]!=' '){
//                 temp+=s[i];
//                 flag=true;
//             }
//             else {
                
//                     reverse(temp.begin(), temp.end());
//                     res=res+temp+' ';
//                     flag=false;
//                     temp="";
                
//             }
//         }
//             reverse(temp.begin(), temp.end());
//             res+=temp;
        
        
        
//         return res;
        
        stack<string>st;
        
        for(int i=0; i<s.size(); i++){
            
            if(s[i]==' ')
                continue;
            
            string word="";
            while(i<s.size() and s[i]!=' '){
                word+=s[i];
                i++;
            }
            st.push(word);
        }
        
        string ans="";
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty()){
                ans+=" ";
            }
        }
        
        return ans;
        
        
    }
};