<center><h1>Spiral Matrix</h1></center>

### Introduction
An `m x n` matrix will be given as input, we should traverse all the elements in spiral order.

Example: 
![](https://hackmd.io/_uploads/rk3CQGhg3.png)
```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```

### Method
We can traverse the given martrix withe four directions: `right`, `down`, `left` and `up`, whenever any boundry is touched, the traverse should turn a round.

### Code
```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if (matrix.empty()) return ans; // Check if matrix is empty

    int rows = matrix.size();
    int cols = matrix[0].size();

    int left = 0, right = cols - 1, top = 0, bottom = rows - 1;

    while (left <= right && top <= bottom) {
        // Traverse right
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // Traverse down
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // Traverse left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse up
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

};
```

###### tags: `Leetcode`