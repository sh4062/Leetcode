class MyStack {
private:
    queue<int> s1;
        queue<int> s2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        queue<int> s1;
        queue<int> s2;
        //cout<<"1";
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        s1.push(x);
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        if(s1.empty()){
            while(!s2.empty()){
                int x = s2.front();
                s2.pop();
                s1.push(x);
            }
            while(s1.size()!=1){
                int x = s1.front();
                s1.pop();
                s2.push(x);
            }
            res = s1.front();
            s1.pop();
        }
        else{
            while(s1.size()!=1){
                int x = s1.front();
                
                s1.pop();
                s2.push(x);
            }
            res = s1.front();
            
            s1.pop();
            
        }
        return res;
        
    }
    
    /** Get the top element. */
    int top() {
        int res;
        if(s1.empty()){
            while(!s2.empty()){
                int x = s2.front();
                s2.pop();
                s1.push(x);
            }
            while(s1.size()!=1){
                int x = s1.front();
                s1.pop();
                s2.push(x);
            }
            res = s1.front();
            
        }
        else{
            while(s1.size()!=1){
                int x = s1.front();
                
                s1.pop();
                s2.push(x);
            }
            res = s1.front();
            
           
            
        }
        return s1.front();
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return s1.empty()&&s2.empty();
        
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