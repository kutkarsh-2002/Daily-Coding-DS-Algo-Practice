class Solution {
public:
    string simplifyPath(string path) {
        /*if(path.size()==1 && path[0]=='/'){
            return "/";
        }
        
        
        string ans="";
        stack<char>st;
        
        for(int i=0; i<path.size(); i++){
            
            if(path[i]=='/' && st.empty()==true){
                st.push('/');
            }
            else if(path[i]=='.')
                continue;
            else if(path[i]=='/' && !st.empty() && st.top()=='/'){
                continue;
            }
            else{
                st.push(path[i]);
            }
              
        }
        string temp="";
        while(!st.empty()){
            if(st.top()!='/'){
                temp+=st.top();
            }
            else{
                ans=ans+temp;
                ans=ans+st.top();
                temp="";
            }
            st.pop();
        }
        
        
        reverse(ans.begin(), ans.end());
        
        if(ans.size()>1 && ans[ans.size()-1]=='/'){
            ans.erase(ans.begin() + ans.size()-1);
        }
        
        return ans;*/
        
        string res="";
    int n = path.length();

    
    stack<string> stk;
    
    for(int i=0;i<n;i++) {
        
        if(path[i]=='/')
            continue;
        
        string tmpPath = "";
        
        while(i<n && path[i]!='/')
            tmpPath+=path[i++];
        
        if(tmpPath==".")
            continue;
        
        else if(tmpPath==".."){ // going one directory up.
            if(!stk.empty())
                stk.pop();
        }
        else // also taking care of this care when (/..someFileName or /...someFileName) this is a valid file.
            stk.push(tmpPath);
    }
    string ans="";
    while(!stk.empty()){
        ans="/"+stk.top()+ans; // inserting in the begining.
        stk.pop();
    }
    
    return (ans==""?"/":ans); // when the stack is empty in this case ( /////// or /../ )
    }
};