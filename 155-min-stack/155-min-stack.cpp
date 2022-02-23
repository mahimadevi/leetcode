class MinStack {
public:
    stack<int> s1;    
    stack<int> s2;   //for store min value at top 
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
	    if(s2.empty() || val<=s2.top()) 
            s2.push(val);	   //agr push krne wali value minimum hui to s2 mein jayegi 
    }
    
    void pop() {
        if(s1.top()==s2.top()) 
            s2.pop();  //if pop krte waqt value minimum hui to s2 se pop krenge
	    s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();   //s2 ke top mein hi minimum value store hai 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */