class MinStack {
public:
    stack<int> data, min;
    int minInt = INT_MAX;
    
    MinStack() {
        min.push(INT_MAX);
    }
    
    void push(int val) {
        data.push(val);
        if(minInt >= val)
        {
            minInt = val;
            min.push(val);
        }
    }
    
    void pop() {
        if(data.top() == minInt)
        {
            min.pop();
            minInt = min.top();
        }
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return minInt;
    }
};