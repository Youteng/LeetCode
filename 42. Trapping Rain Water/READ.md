<center><h1>Trapping Rain Water</h1></center>

[Leetcode Link](https://leetcode.com/problems/trapping-rain-water/)

### Introduction
An evalution map that consists of `n` non-nagetive integers is given, the distance of each bar is one, compute and return how much water will be trapped after raining.

Example 1:
```cpp
height = [0,1,0,2,1,0,1,3,2,1,2,1]
```
![](https://hackmd.io/_uploads/S1RvciK8o.png)


Expeted output is 6.

### Method

Two things needed to know:
1. When the water will be trapped?
2. How much water will be trapped?

For question 1, the thinking will be:
> If a bar `b` can trap water, there are higher bars on each side.

For question 2:
> The height of the lower side is the water level, minus the height of b will be the answer.

![](https://hackmd.io/_uploads/H1ZccsF8o.png)


### Code

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        vector<int> maxLeft(n), maxRight(n);
        
        for(int i = 1; i < n; i++)
        {
            maxLeft[i] = max(height[i-1], maxLeft[i-1]);
        }
        
        for(int i = n-2; i >= 0; i--)
        {
            maxRight[i] = max(height[i+1], maxRight[i+1]);
        }
        
        for(int i = 0; i < n; i++)
        {
            int waterLevel = min(maxLeft[i], maxRight[i]);
            if(waterLevel > height[i])
            {
                res += waterLevel - height[i];
            }
        }
        
        return res;
    }
};
```

###### tags: `Leetcode`