class Solution {
public:
    int scoreOfParentheses(string s) {
        /*stack<char>st;
        int score=0;
        bool flag=true;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')' && !st.empty() && flag=true){
                st.pop();
                score++;
            }
        }
        
        return score;*/
        
        stack<int> st;
        int ind = 0;
        
        for(auto i : s)
        {
			// if we find open parenthesis
			// push the current score into the stack
            if(i == '(')
            {
                st.push(ind);
				// reset the score to 0
                ind = 0;
            }
            else // if we find close parenthesis
            {
                ind = st.top() + max(ind*2 ,1);
                st.pop();
            }
                
        }
        return ind;
    }
};