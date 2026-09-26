class MinStack {
public:
    vector<pair<int,int>>v;
    MinStack() {
        
    }
    
    void push(int value) {
        if(v.empty()){
            v.push_back({value,value});
            return;
        }
        int top=v.back().first;
        int mini=min(value,v.back().second);
        v.push_back({value,mini});
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
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