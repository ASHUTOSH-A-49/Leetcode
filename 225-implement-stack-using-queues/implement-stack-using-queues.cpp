class MyStack {
public:
//APPROACH -2 : using 1 queue
queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n = q.size();
        for(int i = 0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
        int el = q.front();
        q.pop();
        return el;
    }
    
    int top() {
        int n = q.size();
        for(int i = 0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
        int el = q.front();
        q.pop();
        q.push(el);
        return el;
    }
    
    bool empty() {
        return (q.empty());
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