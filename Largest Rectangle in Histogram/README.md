<center><h1>Largest Rectangle in Histogram</h1></center>

[Leetcode Link](https://leetcode.com/problems/largest-rectangle-in-histogram/)

### Introduction
A list that presented the `height` of bars will be given, we should find and return the area of the maxmium rectangle.

Example:
```
INPUT: [1, 4, 2, 3]
OUTPUT: 6
```

![](https://hackmd.io/_uploads/B1Mn6V55o.png)

### Method
One thing we should figure out before starting to code, **how to form a rectangle?**  
Tow ways to form a rectangle:
1. The bar itself.
2. A bar that has higher bars on both sides.

That means we can scan from both sides to find the unique `r` and `l` for each bar `b`, where `r` and `l` represent the position of first bar that lower than `b` on each side, then the rectangle area of bar `b` can be fromed will be `heights[b] * (r - l - 1)`, please know that we only need to minus one since the array index is begin form zero.

And the simplest method to scan from each side is using two for loops:

```cpp
for(int i = 1; i < heights.size(); i++)
{
    int temp = i - 1;
    while(temp >= 0 && heights[temp] >= heights[i])
    {
        temp--;
    }

    left[i] = temp;
}
```

```cpp
for(int i = heights.size() - 2; i >= 0; i--)
{
    int temp = i + 1;
    while(temp < heights.size() && heights[temp] >= heights[i])
    {
        temp++;
    }

    right[i] = temp;
}
```
The time complexity is `O(n^2)`.

Then we can calculate the maxmium area of each bar with a simple for loop:

```cpp
for(int i = 0; i < heights.size(); i++)
{
    maxHist = max(maxHist, heights[i] * (right[i] - left[i] - 1));
}
```

But one thing will be found out if you submit this solution, the results will be TLE since that contains some corner cases like '1' repeats 30000 times and '8035' repeats 67419 times, which makes our nested loops TLE.

A little optimization can be performed to make the amortized time complexity down to `O(n)`, change `temp--` to `temp = left[temp]` and `temp++` to `temp = right[temp]`.
The key idea is that:
> The bar on that side will be higher than `b` if able to go left or right.

So that we can skip lot of iterations since that is been calculated before.
Which is the key concept of the **amortized time complexity**.

```cpp
for(int i = 1; i < heights.size(); i++)
{
    int temp = i - 1;
    while(temp >= 0 && heights[temp] >= heights[i])
    {
        temp = left[temp];
    }

    left[i] = temp;
}
```

```cpp
for(int i = heights.size() - 2; i >= 0; i--)
{
    int temp = i + 1;
    while(temp < heights.size() && heights[temp] >= heights[i])
    {
        temp = right[temp];
    }

    right[i] = temp;
}
```

### Code
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size());
        vector<int> right(heights.size());
        int maxHist = 0;

        left[0] = -1;
        right[right.size() - 1] = heights.size();
        
        //Scan from left
        for(int i = 1; i < heights.size(); i++)
        {
            int temp = i - 1;
            while(temp >= 0 && heights[temp] >= heights[i])
            {
                temp = left[temp];
            }

            left[i] = temp;
        }
        
        //Scan from right
        for(int i = heights.size() - 2; i >= 0; i--)
        {
            int temp = i + 1;
            while(temp < heights.size() && heights[temp] >= heights[i])
            {
                temp = right[temp];
            }

            right[i] = temp;
        }

        //Calcuate the maxmiun area
        for(int i = 0; i < heights.size(); i++)
        {
            maxHist = max(maxHist, heights[i] * (right[i] - left[i] - 1));
        }

        return maxHist;
    }
```

###### tags: 