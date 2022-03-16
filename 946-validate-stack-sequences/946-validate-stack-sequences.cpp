class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int i=0;
        stack<int>st;
        stack<int>temp;
        for(int j=popped.size()-1; j>=0; j--){
            temp.push(popped[j]);
        }
        
        while(i<pushed.size() && !temp.empty()){
            
            /*
            if(pushed[i]!=temp.top()){
                if(!st.empty() && st.top()==temp.top()){
                    st.pop();
                    temp.pop();
        
                }
                
                st.push(pushed[i]);
                i++;
            }
            else if(pushed[i]==temp.top()){
                i++;
                temp.pop();
            }
            */
            
            if(pushed[i]!=temp.top()){
                st.push(pushed[i]);
                i++;
            }
            else if(pushed[i]==temp.top()){
                i++;
                temp.pop();
                while(!st.empty() && !temp.empty() && st.top()==temp.top()){
                    st.pop();
                    temp.pop();
                }
            }
            
            
        }
        
        while(!st.empty() && !temp.empty()){
            
            if(st.top()!=temp.top()){
                return false;
            }
            
            st.pop();
            temp.pop();
            
        }
        
        return (st.empty()==true && temp.empty()==true)?true:false;
        
    }
};