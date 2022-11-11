<center><h1>MinStack</h1></center>

[Leetcode Link](https://leetcode.com/problems/min-stack/)

### Intorduce
We should implement a class which provides five functions, 
`MinStack() void push(int val) void pop() int top() int getMin()`.
<br></br>
`MinStack()` is the constructor, we can do whatever we want when constructing this calss.<br></br>
`void push(int val)` is the stack push function.<br></br>
`void pop()` is the stack pop function, please note that, stacks return nothing when pop in C++.<br></br>
`int top()` returns the topmost value in the stack.<br></br>
`int getMin()` returns the smallest value in the stack.<br></br>

### Architecture
Two stacks are used to store input data and the minimum numbers in the stack.

Init:<br></br>
![](https://i.imgur.com/zazng9S.png)

Insert 3:<br></br>
![](https://i.imgur.com/yoEKfuP.png)


### Methods
#### push(int val)
When a integer comes, do three things:
1. Push into stack Data.
2. Check whether the value smaller than current minimum smallest value, if yes do:
    1. Push into stack Min.
    2. Set current minimum value to the input value.

#### pop()
Two things need to do when pop:
1. Check whether the value intended to be pop is smallest, if yes:
    1. Pop the first value of stack Min.
    2. Set current minimum value to the first value of stack Min.
2. Pop the first value of stack Data.

#### top()
Return top() of stack data.

#### getMin()
Return current minimum value.

### Code
```cpp
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
```

###### tags: `Leetcode`
