<center><h1>The Skyline Problem</h1></center>

### Introduction
A 2D-array that represents `buildings` will be given, each `building` of `buildings` will be formatted as `[left, right, height]`, where `left` indicates the x-axis of the start point of this `building`, and the `right` means the x-axis of the end point.

A array represents **Skyline** should be returned as result, which indicates a list of `keypoints`, which is sorted by their x-axis value.

Exemple:
![](https://hackmd.io/_uploads/BJmSCzIsj.png)

```cpp
Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
```

### Method
We just use an example to describe how to list all the key points:

```cpp
Input : buildings = [[2,9,10],[3,7,15],[5,12,12]]
```

First, all the `points` that indicate the start and end points should be stored into a vector and sorted by x-axis.
Please note that we will set the add a *negative* sign to the height which makes it easier to determine the start points.

```cpp
points = [[2, -10], [3, -15], [5, -12], [7, 15], [9, 10], [12, 12]]
```

After that we can start the for-loop:
1. First, we meet point **2**, which is a start point, and set the `ongoing height` to 10.
2. Next, we meet point **3**, its height is 15, obviously, that is higher than 10, so the `ongoing height` should be set to 15.
3. Next, we meet point **5**, but is height is 12, lower than the `ongoing height`, so we don’t need to change that now, but we still need to store this point in case it fallback.
4. Next is point **7**, which is an end point, so we should remove its height of 15 form the temp, and fallback the `ongoing height` to 12.
5. Next is point **9**, which is an end point, so the height 10 should be removed, and now, the top of temp is 12, and the `ongoing height` is also 12, which means we don't need to change it.
6. Next is **12**, and that is the end, so we should remove it, and change `ongoing height` to 0.

### Code
```cpp
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<pair<int, int>> points;
        multiset<int> tempStack{0};

        for(auto b: buildings)
        {
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }

        sort(points.begin(), points.end());

        int ongoing = 0;

        for(int i = 0; i < points.size(); i++)
        {
            int curPoint = points[i].first;
            int curHeight = points[i].second;

            if(curHeight < 0)
            {
                tempStack.insert(-curHeight);
            }
            else
            {
                tempStack.erase(tempStack.find(curHeight));
            }

            int top = *tempStack.rbegin();

            if(ongoing != top)
            {
                ongoing = top;
                ans.push_back({curPoint, ongoing});
            }
        }

        return ans;
    }
};
```

### Reference
[[C++] Easiest Explanation Ever Guaranteed - Beginner Friendly - Detailed - O(nlogn)](https://leetcode.com/problems/the-skyline-problem/solutions/2094329/c-easiest-explanation-ever-guaranteed-beginner-friendly-detailed-o-nlogn/)

###### tags: `Leetcode`