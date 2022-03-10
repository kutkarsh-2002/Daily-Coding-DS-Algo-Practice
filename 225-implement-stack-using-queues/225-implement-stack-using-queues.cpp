class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
       queue<int>temp;
       if(q.empty()==true){
           q.push(x);
       }
        else{
            while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        
        q.push(x);
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
            
        }
    }
    
    int pop() {
        int res=q.front();
        q.pop();
        return res;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */