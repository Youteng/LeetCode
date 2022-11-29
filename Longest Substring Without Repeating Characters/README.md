<center><h1>Longest Substring without Repeating Characters</h1></center>

### Introduction
A string `s` is provided as input, the length of the longest substring without reapeating characters should be returned.

Example:
```Cpp
s = "abcabcbb"
```
The output should be 3.

### Method

Single traverse can achieve the goal:
1. Traverse the provided string.
2. Whenever a repeated character found, count the length.
3. Move the start pointer to the index of reapting character found.
4. Return the maxmium length.

![](https://hackmd.io/_uploads/ry2zXAZPj.png)

    


### Code

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        int found;
        int max = 0;
        
        if(s.size() == 1) return 1;
        
        for(end; end < s.size(); end++)
        {
            found = s.substr(0, end).rfind(s[end])+1;
            if(found != string::npos)
            {
                if(found >= start)
                {
                    start = int(found);
                }
            }
            max = std::max(max, end-start+1);
        }
        return max;
    }
};
```

###### tags: `Leetcode`