class MinStack {
    stack<int> minstk;
    stack<int> stk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(minstk.empty()){
            minstk.push(val);
        }else{
            minstk.push(min(minstk.top(),val));
        }
        
    }
    
    void pop() {
        if(!stk.empty()){
            stk.pop();
            minstk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
};
