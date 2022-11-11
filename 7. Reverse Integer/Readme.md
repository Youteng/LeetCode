<center><h1>Reverse Integer</h1></center>

[Leetcode Link](//https://leetcode.com/problems/min-stack/submissions/)

### Intorduce
In this problem, we will get a integer as input, the only thing we should do is reverse and return it.

### Method
We can easily resolve this problem mathematically:
1. Initialize the int res as 0.
2. Get the remainder of the input number.
3. Check whether overflow, return 0 if yes. 
4. Calculate: res * 10 + remainder
5. Return res.

### Code
```cpp
class Solution {
public:
    int reverse(int x) {
        int res = 0, a = 0;
        while(x != 0){
            a = x % 10;
            x /= 10;
            if(res > INT_MAX  / 10 || res < INT_MIN / 10) return 0;
            res = res * 10 + a;
        }
        
        return res;    
    }
};
```

###### tags: `Leetcode`