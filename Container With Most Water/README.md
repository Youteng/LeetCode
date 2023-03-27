<center><h1>Container With Most Water</h1></center>

### Introduction
An array `height` that represents the height of vertical lines will be given as input, returns the maxmium water these lines can trap.

Example:  
![](https://hackmd.io/_uploads/SJJoV5Cxn.png)
```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
In this case, the max area of water (blue section) the container can contain is 49.
```

### Method
The answer can be claculated with a easy greedy algorithm:
1. Using two pointers `left` and `right` to indicate the start and end of `height`.
2. Calculate the current area and compare with the local maxmium area.
3. Move the pointer of the lower side by one step closer to another.
4. Repeat til two pointers meet.
5. Return the answer.

### Code
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size() - 1;
        int left = 0;
        int ans = INT_MIN;
        int currArea = 0;

        while(left != right)
        {
            if(height[left] > height[right])
            {
                currArea = (right - left) * height[right];
                right --;
            }
            else
            {
                currArea = (right - left) * height[left];
                left++;
            }

            ans = max(ans, currArea);
        }

        return ans;
    }
};
```

**optimize:**  
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size() - 1;
        int left = 0;
        int ans = INT_MIN;
        int currArea = 0;

        while(left != right)
        {
            currArea = (right - left) * min(height[right], height[left]);
            ans = max(ans, currArea);

            if(height[left] > height[right])
            {
                right --;
            }
            else
            {
                left++;
            }
        }

        return ans;
    }
};
```

###### tags: `Leetcode`