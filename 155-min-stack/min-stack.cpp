//APPROACH  - modify stack to contain pair where it now stores pair <int,int>
// first int is value and second int is min val seen till now


class MinStack {
    int minel = INT_MAX;stack<pair<int,int>> st;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()) minel = value;
        else{
            auto p = st.top();
            minel = min(p.second,value);
        } 
        st.push({value,minel});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        auto p = st.top();
        return p.first;
    }
    
    int getMin() {
        auto p = st.top();
        return p.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */