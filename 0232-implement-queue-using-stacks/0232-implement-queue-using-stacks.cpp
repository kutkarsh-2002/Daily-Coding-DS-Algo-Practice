class MyQueue {
public:
    stack<int>st;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st.empty()==true){
            st.push(x);
        }
        else{
        stack<int>temp;
        
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        
        st.push(x);
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
            
        }
        
    }
    
    int pop() {
        
        int res=st.top();
        st.pop();
        return res;
        
    }
    
    int peek() {
        
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */