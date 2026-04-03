class MinStack {
    private:
        std::stack<int> MinaStack;
        std::stack<int> AvgStack; 
    public:
    MinStack(){}
    
    void push(int val) {
        AvgStack.push(val);
        val = std::min(val, MinaStack.empty() ? val : MinaStack.top());
        MinaStack.push(val);
    }
    
     
    void pop() {
        AvgStack.pop();
        MinaStack.pop();
    }
    
    int top() {
      return AvgStack.top();   
    }
    
    int getMin() {
        return MinaStack.top(); 
    }
};
